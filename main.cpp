#include <iostream>
#include <fstream>

using namespace std;

#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

Material *listaMateriales[20];
Reserva listaReservas[50];
int tamMateriales = 0, tamReservas = 0;

void cargarMateriales() {
    ifstream archMateriales;
    archMateriales.open("material.txt");
    string titulo, autor, sistemaOperativo;
    char tipoMat;
    int idMaterial, numPag, duracion;

    while (archMateriales >> idMaterial >> titulo >> tipoMat) {
        switch (tipoMat) {
        case 'L':
            {
            archMateriales >> numPag >> autor;
            listaMateriales[tamMateriales] = new Libro(idMaterial, titulo, numPag, autor);
            tamMateriales++;
            }
            break;
        case 'S':
            {
            archMateriales >> sistemaOperativo;
            listaMateriales[tamMateriales] = new Software(idMaterial, titulo, sistemaOperativo);
            tamMateriales++;
            }
            break;
        case 'D':
            {
            archMateriales >> duracion;
            listaMateriales[tamMateriales] = new Disco (idMaterial, titulo, duracion);
            tamMateriales++;
            }
            break;
        }
    }
    archMateriales.close();
}

void cargarReservas() {
    ifstream archReservas;
    archReservas.open("reserva.txt");
    int dd, mm, aa, idMaterial, idCliente;

    while (archReservas >> dd >> mm >> aa >> idMaterial >> idCliente) {
        Fecha f1(dd,mm,aa);
        Reserva nuevaReserva(idMaterial, idCliente, f1);
        listaReservas[tamReservas] = nuevaReserva;
        tamReservas++;
     }
     archReservas.close();
}

void descargarReservas() {
    ofstream archReservas;
    archReservas.open("reserva.txt");
    for (int i = 0; i < tamReservas; i++) {
        archReservas << listaReservas[i].getFechaReservacion().getDd() << " " << listaReservas[i].getFechaReservacion().getMm() << " " << listaReservas[i].getFechaReservacion().getAa();
        archReservas << " " << listaReservas[i].getIdMaterial() << " " << listaReservas[i].getIdCliente() << endl;
    }
    archReservas.close();
}

//Recibe como parametro el id del material reservado
//regresa la posicion del id en el arreglo de materiales (-1 si no está)
int buscarMaterial(int idMaterial) {
    for (int i = 0; i < tamMateriales; i++) {
        if (listaMateriales[i]->getIdMaterial() == idMaterial)
            return i;
    }
    return -1;
}

void mostrarMateriales() {
    for (int i = 0; i < tamMateriales; i++) {
        cout << "____________________________________________________________________________________________" << endl;
        listaMateriales[i]->muestra();
        cout << "____________________________________________________________________________________________" << endl;
    }
}

void mostrarReservas() {
    int idMat, pos, cantDias;
    for (int i = 0; i < tamReservas; i++) {

        idMat = listaReservas[i].getIdMaterial();
        pos = buscarMaterial(idMat);
        cout << "____________________________________________________________________________________________" << endl;
        cout << listaMateriales[pos]->getTitulo() << endl;
        cout << "Inicio de reservacion: " << listaReservas[i].getFechaReservacion();
        cantDias = listaMateriales[pos]->cantidadDeDiasDePrestamo();
        cout << "Fin de reservacion: " << listaReservas[i].calculaFechaFinReserva(cantDias);
        cout << "Id del cliente: " << listaReservas[i].getIdCliente() << endl;
        cout << "____________________________________________________________________________________________" << endl;
    }
}

bool validarId(int idMaterial) {
    for (int i = 0; i < tamMateriales; i++){
        if (listaMateriales[i]->getIdMaterial() == idMaterial)
            return true;
    }
    cout << "Id no encontrado" << endl;
    return false;
}

bool validarFecha(Fecha f1) {
    if ((f1.getMm() > 0 && f1.getMm() <= 12) && f1.diasMes() >= f1.getDd())
        return true;
    else {
        cout << "Fecha no valida" << endl;
        return false;
    }
}

bool rangoFecha(Fecha f1, int idMaterial) {
    int posMat, cantDias;
    Fecha fechaFin;
    for (int i = 0; i < tamReservas; i++) {
        if (listaReservas[i].getIdMaterial() == idMaterial) {
            posMat = buscarMaterial(idMaterial);
            cantDias = listaMateriales[posMat]->cantidadDeDiasDePrestamo();
            fechaFin = listaReservas[i].calculaFechaFinReserva(cantDias);
            if ((f1 >= listaReservas[i].getFechaReservacion() && f1 <= fechaFin) || (f1 + cantDias >= listaReservas[i].getFechaReservacion() && f1 + cantDias <= fechaFin))
                return false;
        }
    }
    return true;
}

void consultarReservacionesDeMaterial() {
    int idMat, posMat, cantDias;
    do {
        cout << "Id del material a consultar: ";
        cin >> idMat;
    } while (!validarId(idMat));
    cout << endl;
    for (int i = 0; i < tamReservas; i++) {
        if (listaReservas[i].getIdMaterial() == idMat) {
            posMat = buscarMaterial(idMat);
            cout << "____________________________________________________________________________________________" << endl;
            cout << listaMateriales[posMat]->getTitulo() << endl;
            cout << "Inicio de reservacion: " << listaReservas[i].getFechaReservacion();
            cantDias = listaMateriales[posMat]->cantidadDeDiasDePrestamo();
            cout << "Fin de reservacion: " << listaReservas[i].calculaFechaFinReserva(cantDias) << endl;
            cout << "____________________________________________________________________________________________" << endl;
        }
    }
}

void consultarReservacionesPorFecha() {
    int dd, mm, aa, posMat, cantDias;
    Fecha fechaFin, f1;
    do {
        cout << "Fecha a buscar" << endl;
        cin >> dd >> mm >> aa;
        f1.setFecha(dd,mm,aa);
    } while (!validarFecha(f1));
    cout << "____________________________________________________________________________________________" << endl;
    cout << "Materiales reservados el " << f1 << endl;
    for (int i = 0; i < tamReservas; i++) {
        if (listaReservas[i].getFechaReservacion() <= f1) {
            posMat = buscarMaterial(listaReservas[i].getIdMaterial());
            cantDias = listaMateriales[posMat]->cantidadDeDiasDePrestamo();
            fechaFin = listaReservas[i].calculaFechaFinReserva(cantDias);
            if (f1 <= fechaFin) {
                cout << listaMateriales[posMat]->getTitulo() << endl;
                cout << "Id del cliente: " << listaReservas[i].getIdCliente() << endl;
                cout << "____________________________________________________________________________________________" << endl;
            }
        }
    }
}

void hacerReserva() {
    int idCliente, idMaterial, dd, mm, aa;
    Fecha f1;
    cout << "Id del cliente: ";
    cin >> idCliente;
    do {
        cout << "Id del material a reservar: ";
        cin >> idMaterial;
    } while (!validarId(idMaterial));
    do{
        cout << "Fecha para reservar" << endl;
        cin >> dd >> mm >> aa;
        f1.setFecha(dd,mm,aa);
    } while (!validarFecha(f1));
    if (rangoFecha(f1, idMaterial)) {
        Reserva nueva(idMaterial, idCliente, f1);
        listaReservas[tamReservas] = nueva;
        tamReservas++;
    } else
        cout << "Material ya reservado en esa fecha" << endl;
}

int main()
{
    char opcion;

    cargarMateriales();
    cargarReservas();

    do {
        cout << "____________________________________________________________________________________________" << endl;
        cout << "a) Consultar lista de materiales" << "\t" << "d) Consultar las reservaciones en una fecha" << endl;
        cout << "b) Consultar lista de reservaciones" << "\t" << "e) Hacer una reservacion" << endl;
        cout << "c) Consultar reservaciones de un material" << "\t" << "f) Terminar" << endl;
        cin >> opcion;
        cout << "____________________________________________________________________________________________" << endl;

        switch (opcion) {
        case 'a':
        case 'A':
            mostrarMateriales();
            break;
        case 'b':
        case 'B':
            mostrarReservas();
            break;
        case 'c':
        case 'C':
            consultarReservacionesDeMaterial();
            break;
        case 'd':
        case 'D':
            consultarReservacionesPorFecha();
            break;
        case 'e':
        case 'E':
            hacerReserva();
            break;
        }
    } while (opcion != 'f' && opcion != 'F');

    descargarReservas();

    return 0;
}
