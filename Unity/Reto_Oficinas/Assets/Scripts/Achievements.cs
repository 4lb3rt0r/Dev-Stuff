//
// Achievements.cs
// Lleva la cuenta de las salas transitadas y las horas introducidas al juego para otorgar los logros
//
//
using System.Collections;
using System.Collections.Generic;
using UnityEngine.Networking;
using UnityEngine;

public class Achievements : MonoBehaviour
{
    private int salas = 0;
    static public Achievements Instance;

    private void Awake(){
        if(Instance == null){
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else{
            Destroy(gameObject);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        salas = MenuScene.totalscore / 5;
        StartCoroutine(Upload(salas));
    }

    IEnumerator Upload(int salas) {
        WWWForm form = new WWWForm();
        form.AddField("salas", salas);
        form.AddField("logronueve", "false");
 
        using(UnityWebRequest www = UnityWebRequest.Post("./GiveAchievements.php", form)) {
            yield return www.SendWebRequest();
     
            if(www.result == UnityWebRequest.Result.ConnectionError) {
                Debug.Log(www.error);
            }
            else {
                Debug.Log(www.downloadHandler.text);
            }
        }
    }

    public void logronueve(){
        StartCoroutine(upLogroNueve());
    }

    IEnumerator upLogroNueve() {
        WWWForm form = new WWWForm();
        form.AddField("salas", 0);
        form.AddField("logronueve", "true");
 
        using(UnityWebRequest www = UnityWebRequest.Post("./GiveAchievements.php", form)) {
            yield return www.SendWebRequest();
     
            if(www.result == UnityWebRequest.Result.ConnectionError) {
                Debug.Log(www.error);
            }
            else {
                Debug.Log(www.downloadHandler.text);
            }
        }
    }
}
