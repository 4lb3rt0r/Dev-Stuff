#ifndef HAMBURGUESA_H
#define HAMBURGUESA_H
/*Clase hamburguesa tiene un precio base, dos enteros que representan la opción
  para el tipo de carne y el tipo de cocción y un booleano que representa con/sin aderezo*/

//Constantes que se usan en la clase
const double PRECIO_BASE=80;
const double PRECIO_ADEREZO = 5;

#include "Comida.h"

//Completa de acuerdo a las instrucciones
class Hamburguesa : public Comida//1. Completa el encabezado de la clase, recuerda que hamburguesa deriva de comida
{
    public:
        Hamburguesa();
        void setConAderezo(bool conAderezo_);
        void setTipoCarne(int tipoCarne_);
        void setTipoCoccion(int tipoCoccion_);
        //2. Agrega los métodos de acceso que hacen falta
        bool getConAderezo() {return conAderezo;};
        int getTipoCarne() {return tipoCarne;};
        int getTipoCoccion() {return tipoCoccion;};
        void muestra();
        void calculaPrecioFinal();

    private:
        int tipoCarne, tipoCoccion;
        bool conAderezo;
};

/*Siempre crearemos el objeto Hamburguesa con el CONSTRUCTOR DEFAULT de esta clase,
  Le asignaremos siempre como nombre de la comida: "HAMBURGUESA" (respeta mayúsculas)
  y como precio, el PRECIO_BASE.
  Así mismo iniciemos con los ingredientes básicos (1 en tipo de carne, 1 en tipo de cocción y false en aderezo*/

//3. Agrega el constructor con las características descritas en el comentario de arriba
Hamburguesa :: Hamburguesa() : Comida(){
    nombre = "HAMBURGUESA";
    precio = PRECIO_BASE;
    tipoCarne = 1;
    tipoCoccion = 1;
    conAderezo = false;
}

// Los extra se pueden agregar con los métodos modificadores
void Hamburguesa::setConAderezo(bool conAderezo_){
    conAderezo = conAderezo_;
}

void Hamburguesa::setTipoCarne(int tipoCarne_){
    tipoCarne = tipoCarne_;
}

void Hamburguesa::setTipoCoccion(int tipoCoccion_){
    tipoCoccion = tipoCoccion_;
}

//4. Implementa los métodos de acceso

// los métodos de acceso ya fueron incluidos dentro de la declaracion de la clase :)


/* El método calculaPrecioFinal lo que hace es revisar los extras
   - Si tipo de carne es 2 el precio aumenta 20
   - Si el tipo de cocción es 2 el precio aumenta 10
   - Si el atributo conAderezo es true, el precio aumenta lo que cuesta el aderezo (recuerda que tenemos una constante)
   En este método, el precio (atributo) debe MODIFICARSE de acuerdo a los extras*/
void Hamburguesa::calculaPrecioFinal() {
    //5. Completa la implementación del método de acuerdo a la explicación de arriba.
    // Es muy importante que se modifique el atributo precio.
    if (tipoCarne == 2) {
        precio += 20;
    }
    if (tipoCoccion == 2) {
        precio += 10;
    }
    if (conAderezo == true) {
        precio += PRECIO_ADEREZO;
    }
}

/*El método muestra, construye y despliega la descripción del producto y su precio
  NO MODIFIQUES ESTE MÉTODO, SÓLO ANALIZA COMO SE LLEVÓ A CABO*/
void Hamburguesa::muestra(){
    cout << nombre;
    string letrero1, letrero2;
    if (tipoCarne == 1)
        letrero1 = " DE POLLO";
    else
        letrero1 =" DE RES";
    if (tipoCoccion == 1)
        letrero2 = " a la PLANCHA";
    else
        letrero2 = " a la PARRILLA";
    cout << letrero1 << letrero2;
    if (conAderezo == true)
      cout << " con ADEREZO" << endl;
    else
      cout <<" sin ADEREZO" << endl;
    cout << "Total: $ " << precio << endl;
}

#endif // HAMBURGUESA_H