//MenuScene.cs
//Script para controlar el menu

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Networking;
using UnityEngine.UI;

public class MenuScene : MonoBehaviour
{
    public static int totalscore = 0;
    public static int currentscore = 0;

    //Creamos los codigos para los botones
    //El boton de start carga la escena principal
    public void StartToplay()
    {
        SceneManager.LoadScene("SotanoScene");
    }
    // Start is called before the first frame update
    void Awake()
    {
        StartCoroutine(GetText());
    }

    //Update is called once per frame
    void Update()
    {
        
    }
    IEnumerator GetText()
    {
        using (UnityWebRequest www = UnityWebRequest.Get("./Get.php"))
        {
            www.SetRequestHeader("Access-Control-Allow-Origin", "*");
            yield return www.SendWebRequest();
            totalscore = int.Parse(www.downloadHandler.text) / 5;
            Debug.Log(totalscore);
        }
    }
}
