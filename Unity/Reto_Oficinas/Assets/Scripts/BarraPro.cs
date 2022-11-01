// BarraPro.cs
// Script para animar la barra de vida

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using DG.Tweening;

public class BarraPro : MonoBehaviour
{
    public string nextscene;

    public Text DialogueText;
    public Text DialogueText2;
    int num = 1;
    string amountText = "Actividad: ";
    int currentScore = 1;
    string progressText = "Progreso: 12/";
    
    public Slider liveBar;
    public Color32 fullColor;
    public Color32 mediumColor;
    public Color32 emptyColor;

    public float sizeStep;
    public float delayTime;
    public float finalValue = 0f;
    float DelayFirstTime = 0.5f;
    public Image fillColor;
    float sliderColor;

    // Empieza el coroutine y define la variable del color
    void Start()
    {
            sliderColor = liveBar.maxValue / 3;
            StartCoroutine(StartFillBar());
            DialogueText2.text = amountText + num.ToString();
    }

    void Update(){
    }

    // Función de tiempo para llamar el cambio de color y aumento de la barra de vida
    IEnumerator StartFillBar(){
        Debug.Log(MenuScene.currentscore);
        if(MenuScene.totalscore > MenuScene.currentscore)
        {
            if (num == 6)
            {
                SceneManager.LoadScene(nextscene);
            }
            else if (currentScore >= 12)
            {
                currentScore = 1;
                finalValue = 0;
                num++;
                DialogueText2.text = amountText + num.ToString();
                MenuScene.currentscore++;
            }
            yield return new WaitForSeconds(delayTime);
            finalValue += sizeStep;
            DialogueText.text = progressText + currentScore.ToString();
            currentScore++;
            AddFill();
            UpdateColor();
        }
    }

    // Aumenta el tamaño de la barra de vida
    public void AddFill(){
        liveBar.DOValue(finalValue, 0.0f).SetDelay(DelayFirstTime).OnComplete(
        () => 
        {
            if(DelayFirstTime != 0)
            {
                DelayFirstTime = 0f;
            }
            if(liveBar.value < liveBar.maxValue)
            {
                StartCoroutine(StartFillBar());
            }
        });
    }

    // Cambia el color dependiendo del valor de LiveBar
    void UpdateColor(){
        if(liveBar.value > sliderColor & liveBar.value < (2 * sliderColor)){
            fillColor.color = mediumColor;
        }
        if(liveBar.value > (2 * sliderColor)){
            fillColor.color = fullColor;
        }
    }
}
