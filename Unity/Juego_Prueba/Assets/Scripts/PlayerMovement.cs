using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    //Variables iniciales para la velocidad de traslación y rotación
    public float speed = 1.0f;
    public float rotationSpeed = 1.0f;
    public float jumpForce = 1.0f;

    private Rigidbody physics;

    // Start is called before the first frame update
    void Start()
    {
        //Bloqueo del mouse al momento de correr el juego
        Cursor.lockState = CursorLockMode.Locked;
        Cursor.visible = false;

        physics = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        //Movimiento del personaje (traslación)
        float horizontal = Input.GetAxis("Horizontal");
        float vertical = Input.GetAxis("Vertical");

        transform.Translate(new Vector3(horizontal, 0.0f, vertical) * Time.deltaTime * speed);

        //Rotación del personaje
        float rotationY = Input.GetAxis("Mouse X");

        transform.Rotate(new Vector3(0, rotationY * Time.deltaTime * rotationSpeed, 0));

        //Salto del personaje
        if (Input.GetKeyDown(KeyCode.Space))
        {
            physics.AddForce(new Vector3(0, jumpForce, 0), ForceMode.Impulse);
        }

    }
}