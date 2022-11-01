#ifndef Persona_h
#define Persona_h

#include "Fecha.h"
class Persona {
public:
 Persona();
 Persona(string nombre, Fecha fechaNac);
 string getNombre() { return nombre; };
 void setNombre(string nom) { nombre = nom; };
 Fecha getFechaNac() { return fechaNac; };
 void setFechaNac(Fecha fn) { fechaNac = fn; };
 int calculaEdad();
 virtual void muestraDatos();
protected:
 string nombre;
 Fecha fechaNac;
};
Persona::Persona() {
 Fecha fec (1,1,1999);
 nombre = "N/A";
 fechaNac = fec;
}
Persona::Persona(string nom, Fecha fec) {
 nombre = nom;
 fechaNac = fec;
}
int Persona::calculaEdad() {
    return 2021-fechaNac.getAa();
}
void Persona::muestraDatos() {
 cout<<"Nombre: "<<nombre<<" Edad: "<<calculaEdad() << endl;
}

#endif