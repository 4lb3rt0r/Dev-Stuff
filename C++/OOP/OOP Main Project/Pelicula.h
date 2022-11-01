#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula : public Video {
    public:
        Pelicula();
        Pelicula(int idVideo,string titulo,string genero,int duracion,int calificacion);
        void muestra();

};

Pelicula:: Pelicula () : Video () {

}

Pelicula :: Pelicula (int idVideo,string titulo,string genero,int duracion,int calificacion) : Video (idVideo,titulo,genero,duracion,calificacion){

}

void Pelicula :: muestra() {
    cout<<"= = = = = = = = = = = = = = = ="<<endl;
    cout<<"ID: "<<idVideo<<endl;
    cout<<"Título de la Película: "<<titulo<<endl;
    cout<<"Género: "<<genero<<endl;
    cout<<"Duración: "<<duracion<<" minutos"<<endl;
    cout<<"Calificación: "<<calificacion<<" estrellas"<<endl;
}

#endif