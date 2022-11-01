#ifndef Fecha_h
#define Fecha_h

class Fecha {
public:
 Fecha();
 Fecha(int d, int m, int a);
 void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
 int getDd() { return dd; }
 int getMm() { return mm; }
 int getAa() { return aa; }
private:
 int dd, mm, aa;
};
Fecha::Fecha() {
 dd = 1;
 mm = 1;
 aa = 2000;
}
Fecha::Fecha(int d, int m, int a) {
 dd = d;
 mm = m;
 aa = a;
}

#endif