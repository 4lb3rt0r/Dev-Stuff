// Escribe la clase complejo de acuerdo con la descripci�n


// Para el m�todo muestra usa la siguiente l�nea. 
// cout << real << " + " << imag << "i"<< endl;

#ifndef Fraccion_h
#define Fraccion_h

class Fraccion {
	public:
		//declaraci�n de atributos y m�todos p�blicos
		Fraccion();
		Fraccion(int numerador, int denominador);
		int getNumerador() {return numerador;};
		int getDenominador() {return denominador;};
		void setNumerador(int num) { numerador = num; };
		void setDenominador(int denom) { denominador = denom; };
		Fraccion suma(Fraccion f2);
        Fraccion multiplica(Fraccion f2);
		void muestra();
        void simplifica();
	private:
		//declaraci�n de atributos y m�todos privados
		int numerador,denominador;
};

Fraccion :: Fraccion(){
	numerador = 0;
	denominador = 1;
}

Fraccion :: Fraccion(int num, int denom) {
	if ((num > 0 && denom < 0) || (num < 0 && denom > 0)) {
		num *= -1;
		denom *= -1;
	}
	numerador = num;
	denominador = denom;
}

void Fraccion :: muestra() {
    cout<<numerador<<"/"<<denominador<<" ";
}

Fraccion Fraccion :: suma (Fraccion f2) {
    Fraccion res;
	res.numerador = numerador * f2.denominador + denominador * f2.numerador;
	res.denominador = denominador * f2.denominador;
    res.simplifica();
	
	return res;
}

Fraccion Fraccion :: multiplica (Fraccion f2) {
	Fraccion res;
	res.numerador = numerador * f2.numerador;
	res.denominador = denominador * f2.denominador;
    res.simplifica();
    
	return res;
}

void Fraccion :: simplifica () {
    for (int i = 0; i < 8; i++){
		if (i == 2 || i == 3 || i == 5 || i == 7){
			while (numerador%i == 0 && denominador%i == 0) {
				numerador = numerador/i;
				denominador = denominador/i;
			}
		}
	}
    //return f3;
    
}
#endif

