#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include "Fecha.h"

class Reserva {
public:
    Reserva();
    Reserva(int, int, Fecha);
    void setIdMaterial(int);
    int getIdMaterial();
    void setIdCliente(int);
    int getIdCliente();
    void setFechaReservacion(Fecha);
    Fecha getFechaReservacion();
    Fecha calculaFechaFinReserva(int);

private:
    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva() {
    idMaterial = 0;
    idCliente = 0;
    Fecha f;
    fechaReservacion = f;
}

Reserva::Reserva(int idMat, int idCl, Fecha f1) {
    idMaterial = idMat;
    idCliente = idCl;
    fechaReservacion = f1;
}

void Reserva:: setIdMaterial(int idMat) {
    idMaterial = idMat;
}

int Reserva:: getIdMaterial() {
    return idMaterial;
}

void Reserva:: setIdCliente(int idCl) {
    idCliente = idCl;
}

int Reserva:: getIdCliente() {
    return idCliente;
}

void Reserva:: setFechaReservacion(Fecha f1) {
    fechaReservacion = f1;
}

Fecha Reserva:: getFechaReservacion() {
    return fechaReservacion;
}

Fecha Reserva:: calculaFechaFinReserva(int cantDias) {
    return fechaReservacion + cantDias;
}


#endif // RESERVA_H_INCLUDED
