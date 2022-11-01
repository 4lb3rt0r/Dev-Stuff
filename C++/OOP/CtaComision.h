// Agrega aquí tu clase Cta Comisión que ya hiciste en un ejercicio anterior
#ifndef CtaComision_h
#define CtaComision_h

#include "CtaBanc.h"

class CtaComision : public CtaBanc {
    public:
        CtaComision();
        CtaComision(int n, double s,int c);
        int getComision() { return comision; };
        void setComision(double c) {comision = c;};
        bool retira(double cant);
        void mostrar();
    private:
        int comision;
};

CtaComision :: CtaComision () : CtaBanc() {
    comision = 0;
}

CtaComision :: CtaComision(int n, double s,int c) : CtaBanc(n,s){
    comision = c;
}

bool CtaComision :: retira(double cant) {
    if (saldo >= (cant+comision)) {
        //comision *= cant/100;
        saldo -= cant;
        saldo -= comision;
        return true;
    }
    else
        return false;
}

void CtaComision :: mostrar() {
    cout << "Cuenta: "<< numCuenta<<"\t";
    cout << "Saldo: "<<saldo<<endl;
    cout <<"Comision: " << comision << endl;
}

#endif