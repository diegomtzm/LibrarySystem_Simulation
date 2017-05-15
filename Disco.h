#ifndef DISCO_H_INCLUDED
#define DISCO_H_INCLUDED

#include "Material.h"

class Disco : public Material {
public:
    Disco();
    Disco(int, string, int);
    void setDuracion(int);
    int getDuracion();
    int cantidadDeDiasDePrestamo();
    void muestra();

private:
    int duracion;
};

Disco::Disco() : Material() {
    duracion = 0;
}

Disco::Disco(int id, string tit, int dur) : Material (id, tit) {
    duracion = dur;
}

void Disco::setDuracion(int dur) {
    duracion = dur;
}

int Disco:: getDuracion() {
    return duracion;
}

int Disco:: cantidadDeDiasDePrestamo() {
    return 3;
}

void Disco:: muestra () {
    cout << "Tipo de material: Disco" << endl;
    cout << "ID de material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << duracion << endl;
}

#endif // DISCO_H_INCLUDED
