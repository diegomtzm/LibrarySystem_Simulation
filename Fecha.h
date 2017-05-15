#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
    friend istream& operator>>(istream &is, Fecha);
    friend ostream& operator<<(ostream &os, Fecha);

public:
    Fecha();
    Fecha (int, int, int);
    void setFecha(int, int ,int);
    int getDd();
    int getMm();
    int getAa();
    int diasMes();
    Fecha operator+(int);
    bool operator>(Fecha);
    bool operator<(Fecha);
    bool operator>=(Fecha);
    bool operator<=(Fecha);
    bool operator==(Fecha);

private:
    string nombreMes();
    bool esBisiesto();
    int dd;
    int mm;
    int aa;
};

Fecha::Fecha() {
    dd = 0;
    mm = 0;
    aa = 0;
}

Fecha::Fecha(int d, int m, int a) {
    dd = d;
    mm = m;
    aa = a;
}

void Fecha::setFecha(int d, int m, int a) {
    dd = d;
    mm = m;
    aa = a;
}

int Fecha::getDd() {
    return dd;
}

int Fecha::getMm() {
    return mm;
}

int Fecha::getAa() {
    return aa;
}

string Fecha::nombreMes() {
    switch(mm) {
    case 1:
        return "Ene";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Abr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Ago";
        break;
    case 9:
        return "Sept";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dic";
        break;
    default:
        return "No Valido";
        break;
    }
}

bool Fecha::esBisiesto() {
    if (aa % 4 == 0)
        return true;
    else
        return false;
}

int Fecha:: diasMes() {
    switch(mm) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if (esBisiesto())
                return 29;
            else
                return 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return -1;
    }
}

Fecha Fecha::operator+(int numDias) {
    int dias, diasM, mes = mm, anio = aa;
    dias = dd + numDias;
    diasM = diasMes();

    if (dias > diasM) {
        dias -= diasM;
        mes++;
        if (mes > 12) {
            anio++;
            mes = 1;
        }
    }

    Fecha f1(dias, mes, anio);
    return f1;
}

bool Fecha::operator==(Fecha f2) {
    if (aa == f2.aa && mm == f2.mm && dd == f2.dd)
        return true;
    else
        return false;
}

bool Fecha::operator>(Fecha f2){
    if (aa > f2.aa)
        return true;
    else if (aa < f2.aa)
        return false;
    else if (mm > f2.mm)
        return true;
    else if (mm < f2.mm)
        return false;
    else if (dd > f2.dd)
        return true;
    else
        return false;
}

bool Fecha::operator<(Fecha f2) {
    if (!(*this > f2) && !(*this == f2))
        return true;
    else
        return false;
}

bool Fecha::operator>=(Fecha f2) {
    return *this > f2 || *this == f2;
}

bool Fecha::operator<=(Fecha f2) {
    return *this < f2 || *this == f2;
}

ostream& operator<<(ostream &os, Fecha f1) {
    os << f1.dd << "-" << f1.nombreMes() << "-" << f1.aa << endl;
    return os;
}

istream& operator>>(istream &is, Fecha f1) {
    int d, m , a;
    is >> d >> m >> a;
    return is;
}

#endif // FECHA_H_INCLUDED
