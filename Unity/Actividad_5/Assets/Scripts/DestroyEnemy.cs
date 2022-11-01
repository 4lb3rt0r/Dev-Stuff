/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 5 */

/* Archivo: DestroyEnemy.cs
Se encarga de destruir el objeto del enemigo y añadir puntaje al contador de muertes*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyEnemy : MonoBehaviour
{
    // Inicializamos una variable para contar las muertes de enemigos de tipo entero
    int killCount = 0;

    // Update is called once per frame
    void Update()
    {
        // Si el enemigo cae y pasa el límite de altura debajo del mapa:
        if (transform.position.y < -60)
        {
            //Muere el enemigo xd
            GameObject.Destroy(this.gameObject);
            // Añadimos una muerte al contador de muertes
            killCount++;
            // Enviamos el contador de muertes a la función killScore dentro de ChangeScene mediante una instancia
            ChangeScene.Instance.killScore(killCount);
        }
    }
}
