/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 5 */

/* Archivo: Points.cs
Se encarga de actualizar la cantidad de puntos del score por muerte de un gatito*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Points : MonoBehaviour
{
    // Declaración de una variable pública de tipo Text
    public Text score;
    // Declaración de una variable pública de tipo static int
    public static int points;

    // Start is called before the first frame update
    void Start()
    {
        // Inicializamos el valor de los puntos en 0 por default
        points = 0;
        // Inicializamos el valor de texto del puntaje como "Puntos: " más los puntos por default
        score.text = "Puntos: " + points;
    }

    // Update is called once per frame
    void Update()
    {
        // Actualizamos el valor de texto del puntaje
        score.text = "Puntos: " + points;
        // Llamamos a la función CheckWin() y le enviamos la cantidad de puntos como parámetro
        CheckWin(points);

    }

    // Función encargada de determinar si el jugador ha llegado al puntaje máximo para ganar
    private void CheckWin (int points) {
        // Si el puntaje es mayor o igual a 28:
        if (points >= 28) {
            // Imprimimos en la consola que el jugador ha ganado
            Debug.Log("Ganaste");
            // Llamamos a la función ActiveEndScene()
            ActiveEndScene();
        }
    }

    //Función que cambia a la escena final
    public void ActiveEndScene()
    {
        //Cambio a la escena "EndScene"
        SceneManager.LoadScene("EndScene");
    }
}
