#pragma once

//Declaro la estructura "Estructura" y sus respectivos atributos, constructores, funciones y sobrecargas
struct Estructura {
    string IP;
    int cantidad;
    Estructura();
    Estructura(string IP, int cantidad);
    bool operator < (Estructura estructura);
    bool operator > (Estructura estructura);
    bool operator == (Estructura estructura);
    bool operator <= (Estructura estructura);
    bool operator >= (Estructura estructura);
    friend ostream& operator<<(ostream& os, const Estructura& estructura);
};

//Primer constructor de la estructura "Estructura"
Estructura :: Estructura() {
    cantidad = 0;
}

//Segundo constructor de la estructura "Estructura"
Estructura :: Estructura(string IP, int cantidad) {
    this->IP = IP;
    this->cantidad = cantidad;
}

//Sobrecarga del operador "<"
bool Estructura::operator < (Estructura estructura) {
    return cantidad < estructura.cantidad;
}

//Sobrecarga del operador ">"
bool Estructura::operator > (Estructura estructura) {
    return cantidad > estructura.cantidad;
}

//Sobrecarga del operador "<="
bool Estructura::operator <= (Estructura estructura) {
    return cantidad <= estructura.cantidad;
}

//Sobrecarga del operador ">="
bool Estructura::operator >= (Estructura estructura) {
    return cantidad >= estructura.cantidad;
}

//Sobrecarga del operador "=="
bool Estructura::operator == (Estructura estructura) {
    return cantidad == estructura.cantidad;
}

//Sobrecarga del operador de salida "<<"
ostream& operator<<(ostream& os, const Estructura& estructura){
    os<<"IP: "<<estructura.IP<<" - cantidad de adyacencias: "<<estructura.cantidad;
    return os;
}