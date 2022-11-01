/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Mayo/2022
Actividad: Act 4 */

/* Archivo: DialogManager.cs
 Se encarga de administrar la escritura y transición de cada diálogo*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DialogManager : MonoBehaviour
{
    //Declaramos públicamente una variable de tipo Text que represente el texto a modificar del cuadro de diálogo
    public Text DialogueText;
    //Declaramos públicamente una variable de tipo string que guarde cada línea de diálogo de la historia
    public string[] Sentences;
    //Declaramos públicamente una variable de tipo int que guarde el índice de la línea de diálogo actual
    private int Index;
    //Declaramos públicamente una variable de tipo float que determine la velocidad con la cuál se muestra el texto de diálogo
    public float typingSpeed = 0.05f;
    //Declaramos públicamente una variable de tipo float que determine la velocidad con la cuál se cambie una línea ded diálogo por otra
    public float typingDelay = 0.5f;

    // Start is called before the first frame update
    void Start()
    {
        //Inicializamos la corutina writeSentence() para empezar a escribir los diálogos
        StartCoroutine(writeSentence());
    }

    // Update is called once per frame
    void Update()
    {
        //Por cada frame si se presiona la flecha derecha en el teclado:
        if (Input.GetKeyDown(KeyCode.RightArrow)) {
            //Llamamos a la función Next()
            Next();
        }
    }

    //Función ejecutada cada que se presione el botón de Next o bien se presione la tecla RightArrow
    public void Next() {
        //Detenemos todas las posibles corutinas que estén en proceso
        StopAllCoroutines();
        //Cambiamos a la siguiente línea de diálogo
        Index++;
        //Llamamos a la función NextSentence() para empezar a escribir los diálogos
        NextSentence();
    }

    //Función encargada de actualizar a la línea de diálogo actual
    void NextSentence() {
        //Si aún no se llegó al final de la historia (el límite del string):
        if (Index <= Sentences.Length -1) {
            //Actualizamos la línea de diálogo actual
            DialogueText.text = Sentences[Index];
            //Actualizamos el valor de DialogueText.text para borrar la línea de diálogo anterior
            DialogueText.text = "";
            //Volvemos a llamar a la corutina writeSentence() para escribir la siguiente línea ded diálogo
            StartCoroutine(writeSentence());
        }
    }

    //Corutina encargada de escribir y administrar los tiempos de las líneas de diálogo
    IEnumerator writeSentence() {
        //Temporizador que detiene el cambio entre diálogos en base a la variable typingDelay
        yield return new WaitForSeconds(typingDelay);
        //Por cada caracter dentro de la línea de diálogo actual:
        foreach (char letter in Sentences[Index].ToCharArray()) {
            //Actualizamos al texto del cuadro de diálogo letra por letra
            DialogueText.text += letter;
            //Temporizador que determina la velocidad de escritura entre caracteres
            yield return new WaitForSeconds(typingSpeed);
        }
    }
}