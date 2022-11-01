#ifndef Computadora_h
#define Computadora_h

class Computadora {
	public:
		Computadora();
		Computadora(string marca,string sisOp,int ram);
		string getMarca() { return marca; }
		string getSisOp() { return sisOp; }
		int getRAM() { return ram; }
		void setMarca(string marc) {marca = marc;}
		void setSisOp(string opera) {sisOp = opera;}
		void setRAM(int r) {ram = r;}
		void muestra();
	protected:
		string marca,sisOp;
		int ram;
};

Computadora :: Computadora() {
	marca = " ";
	sisOp = "";
	ram = 0;
}

Computadora :: Computadora(string marc,string opera,int r) {
	marca = marc;
	sisOp = opera;
	ram = r;
}

void Computadora :: muestra() {
	cout<<"Computadora "<<marca;
	cout<<" que contiene el sistema operativo "<<sisOp;
	cout<<" y RAM de "<<ram;
}

#endif
