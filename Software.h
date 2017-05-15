#ifndef SOFTWARE_H_INCLUDED
#define SOFTWARE_H_INCLUDED

#include "Material.h"

class Software : public Material {
public:
    Software();
    Software(int, string, string);
    void setSistemaOper(string);
    string getSistemaOper();
    int cantidadDeDiasDePrestamo();
    void muestra();
private:
    string sistemaOper;
};

Software::Software() : Material() {
    sistemaOper = "NA";
}

Software::Software(int id, string tit, string sist) : Material(id, tit) {
    sistemaOper = sist;
}

void Software:: setSistemaOper(string sist) {
    sistemaOper = sist;
}

string Software::getSistemaOper() {
    return sistemaOper;
}

int Software:: cantidadDeDiasDePrestamo() {
    return 1;
}

void Software:: muestra() {
    cout << "Tipo de material: Software"  << endl;
    cout << "ID de material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Sistema Operativo: " << sistemaOper << endl;
}

#endif // SOFTWARE_H_INCLUDED
