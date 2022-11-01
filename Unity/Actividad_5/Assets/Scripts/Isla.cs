/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 5 */

/* Archivo: Isla.cs
Se encarga de desplegar un mensaje dentro del texto del UI del juego*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Isla : MonoBehaviour
{
    // Inicializamos una variable pública de tipo Text
    public Text msg;
    // Start is called before the first frame update
    void Start()
    {
        // Cambiamos el texto del UI del juego con un mensaje de bienvenida
        msg.text = "Bienvenido a la Isla";
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
