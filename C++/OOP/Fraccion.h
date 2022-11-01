#ifndef Fraccion_h
#define Fraccion_h

class Fraccion {
	public:
		//declaración de atributos y métodos públicos
		Fraccion();
		Fraccion(int numerador, int denominador);
		int getNumerador();
		int getDenominador();
		void setNumerador(int num) { numerador = num; };
		void setDenominador(int denom) { denominador = denom; };
		Fraccion suma(Fraccion f2);
		Fraccion multiplica(Fraccion f2);
		void muestra();
	private:
		//declaración de atributos y métodos privados
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

int Fraccion :: getNumerador() {
	return numerador;
}

int Fraccion :: getDenominador() {
	return denominador;
}

void Fraccion :: muestra() {
	cout<<numerador<<"/"<<denominador<<"\n";
}

Fraccion Fraccion :: suma (Fraccion f2) {
	Fraccion res;
	res.numerador = numerador * f2.denominador + denominador * f2.numerador;
	res.denominador = denominador * f2.denominador;
	
	for (int i = 0; i < 8; i++){
		if (i == 2 || i == 3 || i == 5 || i == 7){
			while (res.numerador%i == 0 && res.denominador%i == 0) {
				res.numerador = res.numerador/i;
				res.denominador = res.denominador/i;
			}
		}
	}
	
	return res;
}

Fraccion Fraccion :: multiplica (Fraccion f2) {
	Fraccion res;
	res.numerador = numerador * f2.numerador;
	res.denominador = denominador * f2.denominador;
	
	for (int i = 0; i < 8; i++){
		if (i == 2 || i == 3 || i == 5 || i == 7){
			while (res.numerador%i == 0 && res.denominador%i == 0) {
				res.numerador = res.numerador/i;
				res.denominador = res.denominador/i;
			}
		}
	}
	
	return res;
}

#endif
