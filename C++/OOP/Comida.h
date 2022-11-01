#ifndef COMIDA_H
#define COMIDA_H

/* La clase comida crea objetos que representan una de las opciones en un restaurante
   Tiene un nombre y un precio
   Comida es la clase base de las clases Hamburguesa y Pizza*/

class Comida
{
    public:
        Comida();
        Comida(string nombre, double precio);
        string getNombre() {return nombre;}
        void setNombre(string nombre_) { nombre = nombre_;}
        double getPrecio() {return precio;}
        void setPrecio(double precio_) { precio= precio_;}
        void muestra();
    protected:
        string nombre;
        double precio;
};

// Constructores
Comida::Comida(){
    nombre = "";
    precio=0;
}

Comida::Comida(string nombre_, double precio_) {
    nombre = nombre_;
    precio=precio_;
}

//Método muestra
void Comida::muestra(){
    cout<<nombre<<" $"<<precio<<endl;
}

#endif // COMIDA_H