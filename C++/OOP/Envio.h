#ifndef Envio_h
#define Envio_h

#include "Persona2.h"
class Envio {
    public:
        Envio();
        Envio(Persona2 remitente ,Persona2 destinatario,double costoEstandar);
        Persona2 getRemitente() { return remitente; };
        Persona2 getDestinatario() { return destinatario; };
        double getCostoEstandar() { return costoEstandar; };
        void setRemitente(Persona2 remi) { remitente = remi; };
        void setDestinatario(Persona2 dest) { destinatario = dest; };
        void setCostoEstandar(double cEst) { costoEstandar = cEst; };
        virtual double calculaCostoEnvio();
    protected:
        Persona2 remitente;
        Persona2 destinatario;
        double costoEstandar;
};
Envio :: Envio() {
    Persona2 perR ("Alberto_Orozco","Durango","Victoria de Durango","34000");
    Persona2 perD ("Alonso_Orozco","Durango","Victoria de Durango","34000");
    costoEstandar = 0;
    remitente = perR;
    destinatario = perD; 
}
Envio :: Envio(Persona2 remi,Persona2 dest,double cEst){
    costoEstandar = cEst;
    remitente = remi;
    destinatario = dest;
}

double Envio :: calculaCostoEnvio(){
    return costoEstandar;
}

#endif