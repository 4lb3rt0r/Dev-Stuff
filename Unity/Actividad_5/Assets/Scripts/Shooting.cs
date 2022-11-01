/* Construcción de Software y Toma de Decisiones - Módulo de Videojuegos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Junio/2022
Actividad: Act 5 */

/* Archivo: Shooting.cs
Se encarga de otorgar al rifle del jugador las mecánicas de disparo*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooting : MonoBehaviour
{ 
    //Declaración pública del RigidBody de la bala
    public Rigidbody bullet;
    //Declaración pública del Vector3 de la velocidad de la bala
    private Vector3 speed;
    //Declaración pública del sonido de la bala de tipo AudioClip
    public AudioClip shot;
    //Declaración pública del rango de la bala de tipo float
    public float range = 10;
    //Declaración pública del objeto de la cámara de tipo Camera
    public Camera cam;
    //Declaración pública de la fuerza provocada por la bala de tipo float
    public float force = -100;

    // Start is called before the first frame update
    void Start()
    {
        //Declaramos el valor de la velocidad inicial de la bala
        speed = new Vector3(100, 0, 0);
    }

    // Update is called once per frame
    void Update()
    {
        //Si se presiona la tecla [K] del teclado:
        if (Input.GetKeyDown(KeyCode.K))
        {
            // Clonamos el objeto de la bala mediante la función Instantiate()
            Rigidbody bulletInstance = Instantiate(bullet, transform.position, transform.rotation);
            // Agregamos velocidad a la bala clonada
            bulletInstance.velocity = transform.TransformDirection(speed);
            //Destruimos la bala clonada 
            Destroy(bulletInstance.gameObject, 1);
            //Reproducimos el sonido de la bala
            AudioSource.PlayClipAtPoint(shot, Camera.main.transform.position, 0.5f);

            //Creamos una línea imaginaria que la bala seguirá hasta el punto de impacto
            RaycastHit hit;
            //Si la línea imaginaria que sigue la bala impacta contra algo:
            if (Physics.Raycast(cam.transform.position, cam.transform.forward, out hit, range))
            {
                //Si la bala impacta contra un cuerpo rígido:
                if (hit.collider.GetComponent<Rigidbody>() != null)
                {
                    //Generamos una fuerza de impacto sobre ese cuerpo rígido
                    hit.collider.GetComponent<Rigidbody>().AddForce(hit.normal * force);
                }
            }
        }
    }
}
