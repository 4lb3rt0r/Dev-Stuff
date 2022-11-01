#ifndef Sobre_h
#define Sobre_h

#include "Envio.h"
class Sobre : public Envio {
    public:
        Sobre();
        Sobre(Persona2 remitente ,Persona2 destinatario,double costoEstandar,double largo,double ancho ,double cargoAdicional);
        double getLargo() { return largo; };
        double getAncho() { return ancho; };
        double getCargoAdicional() { return cargoAdicional; };
        void setLargo(double large) {largo = large;};
        void setAncho(double height) {ancho = height;};
        void setCargoAdicional(double cargoA) {cargoAdicional = cargoA;};
        double calculaCostoEnvio();
    private:
        double largo;
        double ancho;
        double cargoAdicional;
};
Sobre :: Sobre() {
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}
Sobre :: Sobre(Persona2 remitente ,Persona2 destinatario,double costoEstandar,double large,double height ,double cargoA) : Envio (remitente,destinatario,costoEstandar){
    largo = large;
    ancho = height;
    cargoAdicional = cargoA;
}
double Sobre :: calculaCostoEnvio(){
    double total;
    if (largo > 25 && ancho > 30) {
        total = costoEstandar + cargoAdicional;
    }
    else {
        total = costoEstandar;
    }
    return total;
}

#endif