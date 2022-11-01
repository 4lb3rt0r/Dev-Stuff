#ifndef Episodio_h
#define Episodio_h

#include "Video.h"

class Episodio : public Video {
    public:
        Episodio();
        Episodio(int idVideo,string titulo,string genero,int duracion,int calificacion,string ser, int numberEp, int numSeason);
        string getSerie() { return serie; };
        int getNumeroEp() { return numeroEp; };
        int getNumTemporada() { return numTemporada; };
        void setSerie(string ser) { serie = ser;};
        void setNumeroEp(int numberEp) { numeroEp = numberEp; };
        void setNumTemporada(int numSeason) { numTemporada = numSeason; };
        void muestra();
    private:
        string serie;
        int numeroEp;
        int numTemporada;

};

Episodio :: Episodio() : Video () {
    serie = "N/A";
    numeroEp = 0;
    numTemporada = 0;
}

Episodio :: Episodio (int idVideo,string titulo,string genero,int duracion,int calificacion,string ser, int numberEp, int numSeason) : Video (idVideo,titulo,genero,duracion,calificacion){
    serie = ser;
    numeroEp = numberEp;
    numTemporada = numSeason;
}

void Episodio :: muestra() {
    cout<<"= = = = = = = = = = = = = = = ="<<endl;
    cout<<"ID: "<<idVideo<<endl;
    cout<<"Título de la Serie: "<<serie<<endl;
    cout<<"Género: "<<genero<<endl;
    cout<<"Temporada: "<<numTemporada<<endl;
    cout<<"Capítulo: "<<numeroEp<<endl;
    cout<<"Título del Capítulo: "<<titulo<<endl;
    cout<<"Duración: "<<duracion<<" minutos"<<endl;
    cout<<"Calificación: "<<calificacion<<" estrellas"<<endl;
}

#endif