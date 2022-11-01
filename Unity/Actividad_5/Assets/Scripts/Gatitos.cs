/* Construcci�n de Software y Toma de Decisiones - M�dulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 2 */

/*Archivo: Gatitos.cs
Se encarga de controlar las colisiones entre los gatitos y el jugador */

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gatitos : MonoBehaviour
{
    // Variable encargada de otorgar n puntos al jugador cuando el gatito muere en un rango de 0 a 10 puntos
    [Range (0, 10)] public int puntos = 0;

    // Función que se ejecuta cuando el jugador colisiona con el gatito
    private void OnCollisionEnter (Collision collision) {
        // Si el gatito colisiona con el jugador (un objeto con el tag "Player"):
        if (collision.gameObject.tag == "Player") {
            // Añadimos los puntos correspondientes al score
            Points.points += puntos;
            //Se destruye el objeto (matas al gato xd)
            GameObject.Destroy(this.gameObject);
        }
    }
}
