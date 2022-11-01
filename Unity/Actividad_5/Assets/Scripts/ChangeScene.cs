/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 5 */

/* Archivo: ChangeScene.cs
Se encarga de recopilar la cantidad de muertes de los enemigos, actualizar el score de muertes en el UI 
 y de cambiar la escena del juego cuando se maten a todos los enemigos*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ChangeScene : MonoBehaviour
{
    // Declaramos una instancia de tipo ChangeScene para otorgar permisos fuera de este script
    static public ChangeScene Instance;
    // Declaramos un texto de tipo Text para modificar el texto del UI
    public Text textKill;
    // Declaramos un entero para llevar la cantidad de muertes de enemigos
    public int kills;

    // Start is called before the first frame update
    void Start()
    {
        // Inicializamos la variable "kills" en 0
        kills = 0;
        // Modificamos el texto del UI a "Muertes: 0"
        textKill.text = "Muertes: " + kills;
    }

    // Update is called once per frame
    void Update()
    {
        // Por cada frame actuaizaremos el texto del UI con la cantidad de muertes actuales
        textKill.text = "Muertes: " + kills;
    }

    // Función que actualiza la cantidad de muertes y cambia de escena si se matan a todos los enemigos
    public void killScore(int _killCount) {
        // Actualizamos la cantidad de muertes
        kills += _killCount;
        // Si la cantidad de muertes es igual o sobrepasa a 3:
        if (kills >= 3)
        {
            // Cambiamos a la escena "EndScene"
            ActiveEndScene();
        }
    }

    // Función que otorga un valor temporal a la instancia declarada al inicio del script
    private void Awake()
    {
        // Si la instancia se encuentra con un valor nulo:
        if (Instance == null) {
            // Le otorgamos un valor a la instancia
            Instance = this;
        }
    }

    //Función que cambia a la escena final
    public void ActiveEndScene()
    {
        //Cambio a la escena "EndScene"
        SceneManager.LoadScene("EndScene");
    }
}
