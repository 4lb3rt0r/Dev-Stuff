/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Mayo/2022
Actividad: Act 4 */

/* Archivo: PauseMenu.cs
 Se encarga de mostrar los elementos del menu de pausa y detener todos los procesos del juego*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PauseMenu : MonoBehaviour
{
    //Declaración pública de GameIsPaused de tipo static bool para modificar la visibilidad de la pantalla de pausa en el juego
    public static bool GameIsPaused = false;
    //Declaración pública de pauseMenuUI de tipo GameObject para obtener el objeto que contiene los elementos del menu de pausa
    public GameObject pauseMenuUI;
    //Declaración pública de audioSource de tipo AudioSource para obtener el objeto que contiene el audio del juego
    public AudioSource audioSource;
    //Declaración pública de audioSource2 de tipo AudioSource para obtener el objeto que contiene el audio del menú de pausa
    public AudioSource audioSource2;

    // Update is called once per frame
    void Update()
    {
        //Si el juego no se encuentra pausado:
        if (!GameIsPaused) {
            //No reproducimos el sonido del menú de pausa
            audioSource2.Pause();
        }
    }

    //Función encargada de cambiar el estatus entre play y pause del juego
    public void PauseGame() {
        //Si se presiona el botón de play:
        if (GameIsPaused) {
            //Llamamos a la función Resume()
            Resume();
        }
        //Si se presiona el botón de pause:
        else {
            //Llamamos a la función Pause()
            Pause();
        }
    }

    //Función encargada de volver a correr el juego
    public void Resume() {
        //Desactivamos la visibilidad del menu de pausa
        pauseMenuUI.SetActive(false);
        //Reactivamos la escala de tiempo a normal
        Time.timeScale = 1f;
        //Cambiamos el estatus de GameIsPaused a false
        GameIsPaused = false;
        //Reactivamos el audio del juego
        audioSource.Play();
        //Detenemos el audio del menu de pausa
        audioSource2.Pause();
    }

    //Función encargada de pausar el juego
    public void Pause() {
        //Activamos la visibilidad del menu de pausa
        pauseMenuUI.SetActive(true);
        //Cambiamos la escala de tiempo para congelar todos los procesos del juego
        Time.timeScale = 0f;
        //Cambiamos el estatus de GameIsPaused a true
        GameIsPaused = true;
        //Detenemos el audio del juego
        audioSource.Pause();
        //Reactivamos el audio del menu de pausa
        audioSource2.Play();
    }
}
