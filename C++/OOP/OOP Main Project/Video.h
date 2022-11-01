#ifndef Video_h
#define Video_h

class Video {
    public:
        Video();
        Video(int IDVideo,string title,string genre,int duration,int rating);
        int getIdVideo() { return idVideo; };
        string getTitulo() { return titulo; };
        string getGenero() { return genero; };
        int getDuracion() { return duracion; };
        int getCalificacion() { return calificacion; };
        void setIdVideo(int IDVideo) { idVideo = IDVideo; };
        void setTitulo(string title) { titulo = title; };
        void setGenero(string genre) { genero = genre;};
        void setDuracion(int duration) { duracion = duration; };
        void setCalificacion(int rating) { calificacion = rating; };
        virtual void muestra();

    protected:
        int idVideo;
        string titulo;
        string genero;
        int duracion;
        int calificacion;
};

Video :: Video () {
    idVideo = 0;
    titulo = "N/A";
    genero = "N/A";
    duracion = 0;
    calificacion = 0;
}

Video :: Video (int IDVideo,string title,string genre,int duration,int rating) {
    idVideo = IDVideo;
    titulo = title;
    genero = genre;
    duracion = duration;
    calificacion = rating;
}

void Video :: muestra() { //Se que en otras plataformas no necesitas esta parte, pero en VSCODE no puedo correr el código sin esta "funcion" que no hace nada :/
   
}

#endif