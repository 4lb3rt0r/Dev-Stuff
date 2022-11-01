using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Transicion : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void cargarLobby()
    {
        SceneManager.LoadScene("LobbyCorrecto");
    }

    public void cargarAlmacen()
    {
        SceneManager.LoadScene("ArchiveScene");
    }

    public void cargarFabrica()
    {
        SceneManager.LoadScene("FactoryScene");
    }

    public void cargarOficina()
    {
        SceneManager.LoadScene("Oficinas");
    }

    public void cargarEstacionamiento()
    {
        SceneManager.LoadScene("EstacionamientoScene");
    }
}
