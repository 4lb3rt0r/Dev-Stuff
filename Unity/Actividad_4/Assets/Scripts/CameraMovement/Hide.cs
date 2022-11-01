/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Mayo/2022
Actividad: Act 4 */

/* Archivo: Hide.cs
 Se encarga de ocultar los sprites de las aves y la plataforma*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hide : MonoBehaviour
{
    //Declaramos un booleano para saber si el ave se encuentra oculto o no
    bool hidden = false;

    // Update is called once per frame
    void Update()
    {
        //Si se presiona la tecla [H]:
        if (Input.GetKeyDown(KeyCode.H)) {
            //Actualizamos el renderer del ave alternando entre activarlo y desactivarlo (osea que aparezca o desaparezca en la pantalla)
            GetComponent<Renderer>().enabled = !GetComponent<Renderer>().enabled;
            //Si el booleano hidden es verdadero (si se trata de ocultar el ave):
            if (!hidden) {
                //Llamamos a la función Explotion()
                Explotion();
            }
            //Actualizamos el valor de hidden alternando entre true o false
            hidden = !hidden;
        }
    }

    //La función Explotion() se encarga de crear una explosion de particulas para el ave
    void Explotion() {
        //Declaramos una variable part que se encarga de obtener el sistema de particulas del ave
        var part = GetComponent<ParticleSystem>();
        //Reproducimos la animación de particulas del ave
        part.Play();
    }
}
