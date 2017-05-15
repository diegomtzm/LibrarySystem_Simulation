#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

class Material {
public:
    Material();
    Material(int, string);
    void setIdMaterial(int);
    int getIdMaterial();
    void setTitulo(string);
    string getTitulo();
    virtual int cantidadDeDiasDePrestamo() = 0;
    virtual void muestra() = 0;

protected:
    int idMaterial;
    string titulo;
};

Material:: Material() {
    idMaterial = 0;
    titulo = "NA";
}

Material::Material(int id, string tit) {
    idMaterial = id;
    titulo = tit;
}

void Material:: setIdMaterial(int id) {
    idMaterial = id;
}

int Material:: getIdMaterial() {
    return idMaterial;
}

void Material:: setTitulo(string tit) {
    titulo = tit;
}

string Material:: getTitulo() {
    return titulo;
}

#endif // MATERIAL_H_INCLUDED
