/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Mayo/2022
Actividad: Act 4 */

/* Archivo: CameraMovement.cs
 Se encarga de otorgar funcionalidad para alternar entre los escenarios del juego*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        //Si se presiona la tecla de la flecha a la derecha:
        if (Input.GetKeyDown(KeyCode.RightArrow)) {
            //Si la posición de la cámara es menor a 20 en X:
            if (transform.position.x < 20) {
                //Modificamos la posición de la cámara en +20 en X para cambiar el escenario:
                transform.position = new Vector3(transform.position.x + 20, transform.position.y, transform.position.z);
            }
        }
        //Si se presiona la tecla de la flecha a la izquierda:
        if (Input.GetKeyDown(KeyCode.LeftArrow)) {
            //Si la posición de la cámara es mayor a -20 en X:
            if (transform.position.x > -20) {
                //Modificamos la posición de la cámara en -20 en X para cambiar el escenario:
                transform.position = new Vector3(transform.position.x - 20, transform.position.y, transform.position.z);
            }
        }
        //Si se presiona la tecla de la flecha hacia arriba:
        if (Input.GetKeyDown(KeyCode.UpArrow)) {
            //Si la posición de la cámara es mayor a -1 en Y:
            if (transform.position.y > -1) {
                //Modificamos la posición de la cámara en -1 en Y y 6.7 en Z para simular un efecto de zoom:
                transform.position = new Vector3(transform.position.x, transform.position.y - 1, transform.position.z + 6.7f);
            }
        }
        //Si se presiona la tecla de la flecha hacia abajo:
        if (Input.GetKeyDown(KeyCode.DownArrow)) {
            //Si la posición de la cámara es menor a 0 en Y:
            if (transform.position.y < 0) {
                //Modificamos la posición de la cámara en +1 en Y y -6.7 en Z para quitar el efecto de zoom:
                transform.position = new Vector3(transform.position.x, transform.position.y + 1, transform.position.z - 6.7f);
            }
        }

        //Si se presiona la tecla [ESC]:
        if (Input.GetKeyDown("escape")) {
            //Dejamos de correr el juego para volver al editor de Unity
            UnityEditor.EditorApplication.isPlaying = false;
        }
    }
}
