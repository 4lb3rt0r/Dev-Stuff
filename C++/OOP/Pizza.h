#ifndef PIZZA_H
#define PIZZA_H
/*Esta clase describe una comida tipo Pizza, tiene atributos adicionales:
  un arreglo con el nombre de los ingredientes extra
  el número de ingredientes extra que tiene la pizza
  un char que representa el tamaño de la misma*/

#include "Comida.h"

/*Constantes que usa la clase la primera fila son los costos base por tamaño
  y extra representa lo que cuesta agregar un ingrediente extra*/
const double CHICA = 70, MEDIANA = 90, GRANDE = 120, EXTRA=15;
//Esta constante es para el tamaño del arreglo de los ingredientes
const int EXTRA_ING = 3;

class Pizza : public Comida//1. Completa el encabezado de la clase, recuerda que deriva de Comida
{
    public:
        Pizza();
        Pizza(char tamPizza);
        char getTamPizza() {return tamPizza;};
        void setTamPizza(char tamPizza_);
        void setIngredientesExtra(string ingredientes_[EXTRA_ING], int ingExtra_);
        void muestra();
        void calculaPrecioFinal();

    private:
        int ingredientesExtra; // cantidad de ingredientes extra de la pizza, maximo 3
        string ingredientes[EXTRA_ING]; // nombre de los ingredientes
        char tamPizza; //c chica, m mediana, g grande
};


/*Constructor por default siempre crea una pizza chica sin ingredientes extra.
  Inicia Comida con nombre "Pizza" (Respeta las minúsculas) y con el precio de la CHICA
  Inicia el número de ingredientes a 0 y el arreglo de ingredientes con cadenas vacias 
  en cada localidad, así como el tamaño a c (chica)*/

//2. Escribe el constructor por default siguiendo las características que indica el comentario de arriba
Pizza :: Pizza() : Comida () {
    nombre = "Pizza";
    precio=CHICA;
    ingredientesExtra = 0;
    ingredientes[10];
    tamPizza = 'c';
}

/* Constructor que recibe el tamaño de la pizza
   Este constructor inicia la comida a nombre "Pizza" y un costo de 0
   Además se incian el número de ingredientes a 0 y se llena el arreglo con cadenas vacías
   Por último se modifica el precio de acuerdo al tamaño recibido en el parámetro,
   recuerda usar las constantes que tienes con los precios de cada tamaño*/

//3. Escribe el constructor que recibe el tamaño de la pizza de acuerdo al comentario de arriba
Pizza :: Pizza(char tamPizza_) : Comida (nombre,precio) {
    nombre = "Pizza";
    precio = 0;
    ingredientesExtra = 0;
    ingredientes[10];
    tamPizza = tamPizza_;
}

//Método de modificación del tamaño de la pizza
void Pizza::setTamPizza(char tamPizza_) {
      tamPizza = tamPizza_;
      //Modificamos el precio de acuerdo al tamaño
      if (tamPizza == 'c' || tamPizza == 'C' )
        precio = CHICA;
      else if (tamPizza == 'm' || tamPizza == 'M')
        precio = MEDIANA;
      else
        precio = GRANDE;
}



/*Método que recibe arreglo de strings y un entero que representa el número de ingredientes
  Actualiza los datos del arreglo de ingredienes y el atributo ingredientesExtra*/
void Pizza::setIngredientesExtra(string ingredientes_[EXTRA_ING], int ingExtra_){
  ingredientesExtra = ingExtra_;
  for (int i = 0; i < ingredientesExtra && i < EXTRA_ING; i++){
    ingredientes[i] = ingredientes_[i];
  }
}

/*Este método actualiza (incrementa) el precio de acuerdo al número de ingredientes extra, 
  recuerda que cada ingrediente extra tiene un costo dado por la constante EXTRA*/
void Pizza::calculaPrecioFinal(){
  //4. Completa este método, que debe actualizar el atributo precio
    for (int j = 0;j < ingredientesExtra;j++) {
        precio += EXTRA;
    }
    
}

/*Este método muestra la descripción de la pizza con los ingredientes y el precio de la misma
  NO MODIFIQUES ESTE MÉTODO*/
void Pizza::muestra() {
    cout << nombre<< " con " << ingredientesExtra << " ingredientes extra " << endl;
    for (int i = 0; i < ingredientesExtra; i++)
        cout << "----" << ingredientes[i] << endl;
    cout << "Total: $ " << precio << endl;
}

#endif // PIZZA_H