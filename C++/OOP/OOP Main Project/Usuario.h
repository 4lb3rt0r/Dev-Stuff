#ifndef Usuario_h
#define Usuario_h

#include "Video.h"

class Usuario
{
public:
    Usuario();
    //Usuario(string account,string name,int myVideos,int countVid);
    string getNombre() { return nombre; };
    string getCuenta() { return cuenta; };
    int getContVideos() { return contVideos; };
    void setNombre(string name) { nombre = name; };
    void setCuenta(string account) { cuenta = account; };
    int getUnIdMisVideos(int n);
    bool operator+=(int id);

private:
    string cuenta;
    string nombre;
    int misVideos[20];
    int contVideos;
};

Usuario ::Usuario()
{
    cuenta = "4lb3rt0r";
    nombre = "Alberto";
    contVideos = 0;
    for (int i = 0; i < 20; i++)
    {
        this->misVideos[i] = 0;
    }
    
}

//Usuario :: Usuario (string account,string name,int myVideos,int countVid) {    //No es útil para este código
//    cuenta = account;
//    nombre = name;
//    contVideos = 0;
//}

int Usuario ::getUnIdMisVideos(int N)
{
    int a;
    if (N < 20 || N >= 0)
    {
        a = misVideos[N];
    }
    else
    {
        a = -1;
    }
    return a;
}

bool Usuario ::operator+=(int ID)
{
    bool a;
    if (contVideos == 20)
    {
        a = false;
    }
    else
    {
        for (int i = 0; i < 20; i++)
        {
            if (misVideos[i] == ID)
            {
                a = false;
            }
            else if (i == 19)
            {
                misVideos[contVideos] = ID;
                contVideos++;
                a = true;
                //break;
            }
        }
    }

    return a;
}

#endif