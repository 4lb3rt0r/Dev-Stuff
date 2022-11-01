#ifndef Paquete_h
#define Paquete_h

#include "Envio.h"
class Paquete : public Envio {
    public:
        Paquete();
        Paquete(Persona2 remitente ,Persona2 destinatario,double costoEstandar,double peso,double costoKG);
        void setPeso(double weigth) {peso = weigth;};
        void setcostoKG(double priceKG) {costoKG = priceKG;};
        double getPeso() { return peso; }
        double getCostoKG() { return costoKG; }
        double calculaCostoEnvio();
    private:
        double peso;
        double costoKG;
};
Paquete :: Paquete() {
    peso = 0;
    costoKG = 0;
}
Paquete :: Paquete(Persona2 remitente ,Persona2 destinatario,double costoEstandar,double weigth,double priceKG) : Envio (remitente,destinatario,costoEstandar){
    peso = weigth;
    costoKG = priceKG;
}
double Paquete :: calculaCostoEnvio(){
    double total;
    total = costoEstandar + costoKG * peso;
    return total;
}

#endif