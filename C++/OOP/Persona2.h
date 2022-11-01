#ifndef Persona2_h
#define Persona2_h

class Persona2 {
    public:
        Persona2();
        Persona2(string name, string state, string city, string CP);
        void setPersona2(string name, string state, string city, string CP) { nombre = name; estado = state; ciudad = city; cp = CP; }
        string getNombre() { return nombre; }
        string getEstado() { return estado; }
        string getCiudad() { return ciudad; }
        string getCp() { return cp; }
        void imprimir();
    private:
        string nombre,estado,ciudad,cp;
};

Persona2 :: Persona2 () {
    nombre = "N/A";
    estado = "N/A";
    ciudad = "N/A";
    cp = "N/A";
}
Persona2 :: Persona2 (string name,string state,string city,string CP) {
    nombre = name;
    estado = state;
    ciudad = city;
    cp = CP;
}
void Persona2 :: imprimir() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Dirección: "<<estado<<" "<<ciudad<<" "<<cp<<endl;
}

#endif