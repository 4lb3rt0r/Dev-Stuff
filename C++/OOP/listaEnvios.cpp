#include <iostream>
#include <fstream>
using namespace std;

#include "Sobre.h"
#include "Paquete.h"

int main () {
    Envio *listaEnvios[20];

    ifstream archEnvio;
    int cantEnvios,tE,res;
    char tipoEnvio,listaTipos[20];
    string nombreR,estadoR,ciudadR,cpR,nombreD,estadoD,ciudadD,cpD;
    double costoEstandar,peso,costoKG,largo,ancho,cargoAdicional;
    Persona2 remitente,destinatario,remi,desti;

    archEnvio.open("datosEnvios.txt");
    cantEnvios = 0;
    tE = 0;
    res = 0;

     while (archEnvio>>tipoEnvio) {
         if (tipoEnvio == 'p') {
             archEnvio>>nombreR>>estadoR>>ciudadR>>cpR>>nombreD>>estadoD>>ciudadD>>cpD>>costoEstandar>>peso>>costoKG;
             remitente.setPersona2(nombreR,estadoR,ciudadR,cpR);
             destinatario.setPersona2(nombreD,estadoD,ciudadD,cpD);
             Paquete *paq = new Paquete(remitente,destinatario,costoEstandar,peso,costoKG);
             listaEnvios[cantEnvios] = paq;
             listaTipos[cantEnvios] = 'p';
             cantEnvios++;
         }
         else if (tipoEnvio == 's') {
             archEnvio>>nombreR>>estadoR>>ciudadR>>cpR>>nombreD>>estadoD>>ciudadD>>cpD>>costoEstandar>>largo>>ancho>>cargoAdicional;
             remitente.setPersona2(nombreR,estadoR,ciudadR,cpR);
             destinatario.setPersona2(nombreD,estadoD,ciudadD,cpD);
             Sobre *sob = new Sobre(remitente,destinatario,costoEstandar,largo,ancho,cargoAdicional);
             listaEnvios[cantEnvios] = sob;
             listaTipos[cantEnvios] = 's';
             cantEnvios++;
         }
     }
     archEnvio.close();

     for (int i = 0; i< cantEnvios; i++) {
             cout<<"Remitente:"<<endl;
             remi = listaEnvios[i]->getRemitente();
             remi.imprimir();
             cout<<"Destinatario:"<<endl;
             desti = listaEnvios[i]->getDestinatario();
             desti.imprimir();
             res = listaEnvios[i]->calculaCostoEnvio();
             cout<<"Costo: "<<res<<endl;
             tE += res;
     }
     cout<<"Total envios: "<<tE<<endl;

    return 0;
}