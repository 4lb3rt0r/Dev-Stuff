#ifndef Estudiante_h
#define Estudiante_h

#include "Persona.h"
class Estudiante : public Persona {
public:
 Estudiante();
 Estudiante(string nombre,Fecha f,string carrera);
 string getCarrera() { return carrera; }
 void setCarrera(string ca) { carrera = ca; }
 void muestraDatos();
private:
 string carrera;
};
Estudiante::Estudiante() : Persona() {
 carrera = "N/A";
}
Estudiante::Estudiante(string n, Fecha f,string ca) : Persona(n, f) {
 carrera = ca;
}
void Estudiante::muestraDatos() {
 cout<<"Nombre: "<<nombre<<" Edad: "<<calculaEdad()<<" Carrera: "<<carrera << endl;
}
#endif /* Estudiante_h */
