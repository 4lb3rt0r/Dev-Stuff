//
//  Complejo.h
//  arregloComplejos
//
//  Created by Yolanda MartÃ­nez on 9/16/13.
//  Copyright (c) 2013 Yolanda MartÃ­nez. All rights reserved.
//

#ifndef arregloComplejos_Complejo_h
#define arregloComplejos_Complejo_h


class Complejo{

public:
    Complejo();
    Complejo(int r, int i);
	int getReal();
	void setReal(int r);
	int getImag();
	void setImag(int i);
    Complejo operator+(Complejo otro);
    Complejo operator-(Complejo otro);
    Complejo operator*(double numero);
    bool operator==(Complejo c2);
    Complejo operator++();
	void muestra();
private:
    int real, imag;
};

Complejo::Complejo() {
    real = 0;
    imag = 0;
}

Complejo::Complejo(int r, int i) {
    real = r;
    imag = i;
}

int Complejo:: getReal() {
    return real;
}

void Complejo:: setReal(int r) {
    real = r;
}

int Complejo:: getImag() {
    return imag;
}

void Complejo:: setImag(int i) {
    imag = i;
}

Complejo Complejo:: operator+ (Complejo otro) {
    Complejo resultado;
    resultado.real = real + otro.real;
    resultado.imag = imag + otro.imag;
    
    return resultado;
}

Complejo Complejo:: operator- (Complejo otro) {
    Complejo resultado;
    resultado.real = real - otro.real;
    resultado.imag = imag - otro.imag;
    
    return resultado;
}

Complejo Complejo :: operator*(double numero) {
    Complejo resultado;
    resultado.real = real * numero;
    resultado.imag = imag * numero;

    return resultado;
}

bool Complejo:: operator== (Complejo c2) {
    if (this->real == c2.real && this->imag == c2.imag){
        return true;
    }
    else {
        return false;
    }
}

Complejo Complejo :: operator++() {
    real++;
    imag++;

    return *this;
}

void Complejo:: muestra() {
    cout << real << " + " << imag << "i"<< endl;
}


#endif
