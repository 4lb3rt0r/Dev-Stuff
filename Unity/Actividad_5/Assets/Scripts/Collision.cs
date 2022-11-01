/* Construcci�n de Software y Toma de Decisiones - M�dulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 2 */

/*Archivo: Collision.cs
Se encarga de controlar las colisiones entre los gatitos y el jugador */

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cat_Collision : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //Función que se ejecuta cuando el jugador colisiona con el gatito
    private void OnCatCollision (Collision collision) {
        //Si el gatito colisiona con el jugador (un objeto con el tag "Player"):
        if (collision.gameObject.tag == "Player") {
            // Se destruye el objeto (matas al gato xd)
            GameObject.Destroy(this.gameObject);
        }
    }
}
