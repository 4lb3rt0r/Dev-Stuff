#include <iostream>
#include <fstream>
using namespace std;

#include "Pelicula.h"
#include "Episodio.h"
#include "Usuario.h"

int main() {
    Video *listaStreaming[50];

    ifstream archCuenta;
    char tipoMultimedia, opcion;
    string nombreArch, t, g, tSerie, ct, ct2, n, cu3nta;
    int idVideo, d, calif, ep, temp, count, count2, c, c2, id, id2, id3;

    Usuario usu;

    count = 0;

    cout << "Introduzca a continuación el nombre del archivo .txt:" << endl;
    cin >> nombreArch;
    archCuenta.open(nombreArch.c_str());

    while (archCuenta >> tipoMultimedia >> idVideo >> t >> g >> d >> calif)
    {
        if (tipoMultimedia == 'p')
        {
            Pelicula *peli = new Pelicula(idVideo, t, g, d, calif);
            listaStreaming[count] = peli;
        }
        else if (tipoMultimedia == 'e')
        {
            archCuenta >> tSerie >> ep >> temp;
            Episodio *epi = new Episodio(idVideo, t, g, d, calif, tSerie, ep, temp);
            listaStreaming[count] = epi;
        }
        count++;
    }
    archCuenta.close();

    do
    {
        cout << "MENÚ DE OPCIONES" << endl;
        cout << endl;
        cout << "a) Consultar la lista de videos disponibles." << endl;
        cout << "b) Consultar la lista de Videos con cierta calificación." << endl;
        cout << "c) Consultar la lista de Videos por género." << endl;
        cout << "d) Ver datos del usuario." << endl;
        cout << "e) Modificar el perfil del usuario." << endl;
        cout << "f) Agregar video a la lista del usuario." << endl;
        cout << "g) Terminar (Cerrar Sesión)." << endl;

        cout << "Teclee una opción a continuación: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 'a':
        {
            for (int i = 0; i < count; i++)
            {
                listaStreaming[i]->muestra();
            }
            break;
        }

        case 'b':
        {
            bool b;
            cout << "Ha elegido búsqueda por calificación" << endl;
            b = false;
            while (b == false)
            {
                cout << "Teclee a continuación una calificación: ";
                cin >> c;
                count2 = 0;
                for (int i = 0; i < count; i++)
                {
                    c2 = listaStreaming[i]->getCalificacion();
                    if (c == c2 && (c >= 0 || c <= 5))
                    {
                        listaStreaming[i]->muestra();
                        count2++;
                        b = true;
                    }
                    else if (count2 == 0 && i == count - 1)
                    {
                        cout << "No hay resultados de la búsqueda :/" << endl;
                    }
                }
            }

            break;
        }

        case 'c':
        {
            bool b;
            cout << "Ha elegido búsqueda por categoría." << endl;
            b = false;
            cout << "**Atención: Reemplace los espacios con guión bajo [_]" << endl;
            while (b == false)
            {
                cout << "Teclee a continuación una categoría: ";
                cin >> ct;
                count2 = 0;
                for (int i = 0; i < count; i++)
                {
                    ct2 = listaStreaming[i]->getGenero();
                    if (ct == ct2)
                    {
                        listaStreaming[i]->muestra();
                        b = true;
                    }
                    else if (count2 == 0 && i == count - 1)
                    {
                        cout << "No hay resultados de la búsqueda :/" << endl;
                    }
                }
            }

            break;
        }

        case 'd':
        {
            int ind;
            cout << "= = = = = = = = = = = = = = = =" << endl;
            cout << "Mostrando datos de Usuario:" << endl;
            cout << endl;
            cout << "Cuenta Registrada: " << usu.getCuenta() << endl;
            cout << "Nombre del Usuario: " << usu.getNombre() << endl;
            cout << "Contenido Multimedia Registrado en la Lista: " << usu.getContVideos() << endl;

            if (usu.getContVideos() == 0)
            {
                cout << "No se encuentra contenido multimedia en tu lista :/" << endl;
            }
            else
            {
                for (int i = 0; i < usu.getContVideos(); i++)
                {
                    ind = usu.getUnIdMisVideos(i);
                    for (int j = 0; j < count; j++)
                    {
                        //cout << "comparando "<<ind<<" con "<<listaStreaming[j]->getIdVideo()<<endl;
                        if (ind == listaStreaming[j]->getIdVideo())
                        {
                            //cout << "xd" << endl;
                            listaStreaming[j]->muestra();
                            break;
                        }
                    }
                }
            }
            cout << "= = = = = = = = = = = = = = = =" << endl;

            break;
        }

        case 'e':
        {
            cout << "Ha elegido editar información del Usuario." << endl;
            cout << "Ingrese a continuación la nueva cuenta del usuario" << endl;
            cin >> cu3nta;
            usu.setCuenta(cu3nta);
            cout << "Ingrese a continuación el nuevo nombre de usuario" << endl;
            cin >> n;
            usu.setNombre(n);
            break;
        }

        case 'f':
        { //tiene fallos que no pude corregir a tiempo :(
            bool b;
            cout << "Ha elegido añadir contenido multimedia a su lista." << endl;
            b = false;
            while (b == false)
            {
                cout << "Por favor ingrese a continuación el ID de la pelicula/serie o bien teclee [0] para volver al menú:" << endl;
                cin >> id;
                if (id == 0)
                {
                    //b = true;
                    break;
                }
                //for (int i = 0; 0 < count; i++)
                for (int i = 0; 0 < 11; i++)
                {
                    id2 = listaStreaming[i]->getIdVideo();
                    if (id == id2)
                    {
                        b = true;
                        break;
                    }
                }
            }

            if (b == true)
            {
                if ((usu += id) == true)
                {
                    cout << "El contenido multimedia se ha agregado con éxito :D" << endl;
                }
                else
                {
                    cout << "No fue posible agregar el contenido multimedia con éxito :(" << endl;
                }
            }

            break;
        }
        }

    } while (opcion != 'g');
    cout << "Espere un momento por favor..." << endl;
    cout << "Cerrando Sesión";

    return 0;
}