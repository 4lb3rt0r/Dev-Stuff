#ifndef Maestro_h
#define Maestro_h

#include "Persona.h"
class Maestro : public Persona {
public:
 Maestro();
 Maestro(string nombre, Fecha f, string depto);
 string getDepto() { return depto; };
 void setDepto(string de) { depto = de; };
 void muestraDatos();
private:
 string depto;
};
Maestro::Maestro() : Persona() {
 depto = "N/A";
}
Maestro::Maestro(string nomb, Fecha f, string de) : Persona(nomb, f) {
 depto = de;
}
void Maestro::muestraDatos() {
 cout<<"Nombre: "<<nombre<<" Edad: "<<calculaEdad()<<" Depto: "<<depto << endl;
}

#endif