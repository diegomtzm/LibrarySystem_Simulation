#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include "Material.h"

class Libro : public Material {
public:
    Libro();
    Libro(int, string, int, string);
    void setNumPag(int);
    int getNumPag();
    void setAutor(string);
    string getAutor();
    int cantidadDeDiasDePrestamo();
    void muestra();

private:
    int numPag;
    string autor;
};

Libro::Libro():Material() {
    numPag = 0;
    autor = "NA";
}

Libro::Libro(int id, string tit, int num, string aut) : Material (id, tit) {
    numPag = num;
    autor = aut;
}

void Libro::setNumPag(int num) {
    numPag = num;
}

int Libro:: getNumPag() {
    return numPag;
}

void Libro:: setAutor(string aut) {
    autor = aut;
}

string Libro:: getAutor() {
    return autor;
}

int Libro:: cantidadDeDiasDePrestamo() {
    return 10;
}

void Libro:: muestra() {
    cout << "Tipo de material: Libro" << endl;
    cout << "ID de material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "# de paginas: " << numPag << endl;
}

#endif // LIBRO_H_INCLUDED
