using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bob_Transicion : MonoBehaviour
{
    public float velocity;
    // Start is called before the first frame update
    void Start()
    {
 
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.position += Vector3.right * Time.deltaTime * velocity;
        if (transform.position.x > 3)
        {
            GameObject.Destroy(this.gameObject);
        }
    }

}
