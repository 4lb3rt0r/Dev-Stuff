/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Mayo/2022
Actividad: Act 4 */

/* Archivo: FillBar.cs
 Se encarga de animar la barra de vidas contenida dentro del panel*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;

public class FillBar : MonoBehaviour
{
    //Declaración pública de liveBar de tipo Slider para la barra de vida
    public Slider liveBar;
    //Declaración pública de filledColor de tipo Color para establecerel color de la barra de vida llena
    public Color32 filledColor;
    //Declaración pública de midColor de tipo Color para establecer el color de la barra de vida a medio llenado
    public Color32 midColor;
    //Declaración pública de emptyColor de tipo Color para el color de la barra de vida casi vacía
    public Color32 emptyColor;

    //Declaración pública de sizeStep de tipo float para determinar el llenado de la barra de vida
    public float sizeStep;
    //Declaración pública de delayTime de tipo float para determinar el tiempo de demora del llenado de la barra de vida
    public float delayTime;
    //Declaración pública de finalValue de tipo float para determinar el valor final de la barra de vida
    public float finalValue = 0.0f;
    //Declaración de delayFTime de tipo float para determinar el tiempo inicial de demora del llenado de la barra de vida
    float delayFTime = 0.1f;
    //Declaración pública de fillColor de tipo Image para determinaer cuál imagen se estará manipulando como barra de vida
    public Image fillColor;
    //Declaración de sliderColor de tipo float para dividir el valor de la barra de vida en 3 partes
    float sliderColor;

    // Start is called before the first frame update
    void Start()
    {
        //Se establece el valor inicial de la barra de vida en 3 partes
        sliderColor = liveBar.maxValue / 3;
        //Inicializamos la corutina del llenado de la barra de vida
        StartCoroutine(FillBarStarter());
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //Corutina que se encarga de llenar la barra de vida
    IEnumerator FillBarStarter() {
        //Tiempo de demora para actualizar el tamaño de la barra de vida
        yield return new WaitForSeconds(delayTime);
        //Actualizamos el valor final de la barra de vida con respecto al valor diferencial de sizeStep
        finalValue += sizeStep;
        //Llamamos a la funcion IncrementFill()
        IncrementFill();
        //Llamamos a la funcion UpdateColor()
        UpdateColor();
    }

    //Función que se encarga de incrementar el valor de la barra de vida con animación
    public void IncrementFill() {
        //Alteramos el valor del tamaño de liveBar conforme el llenado de la misma barra de vida con el tiempo de demora delayFTime
        liveBar.DOValue(finalValue, 0.3f).SetDelay(delayFTime).OnComplete(
            () => {
                //Si el valor de delayFTime no es 0:
                if(delayFTime != 0){
                    //Establecemos el valor de delayFTime en 0
                    delayFTime = 0f;
                }
                //Si el valor de liveBar es menor a su valor máximo:
                if (liveBar.value < liveBar.maxValue) {
                    //Llamamos a la corutina FillBarStarter()
                    StartCoroutine(FillBarStarter());
                }
            }

        );
    }

    //Función que se encarga de actualizar el color de la barra de vida
    void UpdateColor() {
        //Si el valor de liveBar es mayor que el 1er tercio de la barra de vida pero menor que el 3er tercio:
        if (liveBar.value > sliderColor && liveBar.value < (sliderColor * 2)) {
            //Pintamos la barra de amarillo (o el color correspondiente a medio llenado):
            fillColor.color = midColor;
        }
        //Si no, si el valor de liveBar es mayor que el 3er tercio de la barra de vida:
        else if (liveBar.value > (sliderColor * 2)) {
            //Pintamos la barra de verde (o el color correspondiente a llenado casi completo):
            fillColor.color = filledColor;
        }
        //Si no es ninguna de las anteriores, por descarte la barra es baja, por lo que:
        else {
            //Pintamos la barra de rojo (o el color correspondiente a llenado casi vacío):
            fillColor.color = emptyColor;
        }
    }
}
