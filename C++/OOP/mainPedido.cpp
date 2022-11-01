#include <iostream>
#include <string>

using namespace std;

#include "Pizza.h"
#include "Hamburguesa.h"

const int MAX_INGREDIENTES = 3;

/*Este método tiene la interacción con el cliente para obtener los datos adicionales de la pizza
  observa lo que hace y completa lo que se te pide*/
void pidePizza(Pizza &miPizza){
  char tamanio;
  int adicionales;
  string ingredientes[MAX_INGREDIENTES];
  //cout << "\nPIZZA\nTamanio de tu pizza <c=CHICA, m=MEDIANA, g=GRANDE>: "; DÉJALO COMO COMENTARIO
  cin >> tamanio;
  //cout << "Ingredientes adicionales <0 .. 3>: "; DÉJALO COMO COMENTARIO
  cin >> adicionales;
  for (int i = 0; i < adicionales && i < MAX_INGREDIENTES; i++){
    //cout << "Ingrediente[" << i+1 << "]: "; DÉJALO COMO COMENTARIO
    cin >> ingredientes[i];
  }
  //1. Con los datos recibidos modifica el tamaño y los ingredientes en el objeto miPizza
  miPizza.setIngredientesExtra(ingredientes,adicionales);
  miPizza.setTamPizza(tamanio);
    
  //2. Actualiza el precio final de la pizza, llama al método correspondiente.  
  miPizza.calculaPrecioFinal();
}


/*Este método tiene la interacción con el cliente para obtener los datos adicionales de la hamburguesa
  observa lo que hace y completa lo que se te pide*/
void pideHamburguesa(Hamburguesa &miBurger){
  int tipoCarne, tipoCoccion;
  char aderezo;
  bool conAderezo;
  //cout << "\nHAMBURGUESA\nTipo de carne <1=POLLO, 2=RES>: "; DÉJALO COMO COMENTARIO
  cin >> tipoCarne;
  //cout << "Tipo coccion <1=PLANCHA, 2=PARRILLA>: "; DÉJALO COMO COMENTARIO
  cin >> tipoCoccion;
  //cout << "Con aderezo? <s=SI, n=NO>: "; DÉJALO COMO COMENTARIO
  cin >> aderezo;
  if (aderezo == 's'){
    conAderezo = true;
  }
  else {
    conAderezo = false;
  }
  //3. Con los datos recibidos modifica los atributos correspondientes del objeto miBurger
  miBurger.setConAderezo(conAderezo);
  miBurger.setTipoCarne(tipoCarne);
  miBurger.setTipoCoccion(tipoCoccion);
 // 4. Actualiza el precio final de la hamburguesa, llama al método correspondiente. 
  miBurger.calculaPrecioFinal();
    
    
}

// Porgrama principal, REVÍSALO, pero NO NECESITAS MODIFICAR NADA
int main() {
  double totalPedido=0;
    
  Pizza miPizza;
  pidePizza(miPizza);
  totalPedido+=miPizza.getPrecio();
  
  Hamburguesa miBurger;
  pideHamburguesa(miBurger);
  totalPedido+=miBurger.getPrecio();
  
  Comida miPostre("PAY",50);
  totalPedido+=miPostre.getPrecio();
  
  miBurger.muestra();
  miPizza.muestra();
  miPostre.muestra();
  cout<<"Total del pedido: $"<<totalPedido<<endl;
  return 0;
}