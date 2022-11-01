//UIController.cs
//Script para controlar los elementos del HUD

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIController : MonoBehaviour
{

    // Update is called once per frame
    void Update()
    {
        
    }
    public void ReturntoMenu()
    {
        GameControl.Instance.GotoMenu();
    }
}
