//GameControl.cs
//Script que se encarga de controlar todos los scripts del juego

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameControl : MonoBehaviour
{
    //Creamos las variables necesarias para asignaralas a los objetos de la escena
    public static GameControl Instance;
    public UIController uiController;
    public void GotoMenu()
    {
        SceneManager.LoadScene("MenuScene");
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}