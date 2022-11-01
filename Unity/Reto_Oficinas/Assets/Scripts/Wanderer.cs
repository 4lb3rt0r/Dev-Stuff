using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// This makes an object move randomly in a set of directions, with some random time delay in between each decision
/// </summary>
public class Wanderer : MonoBehaviour

{

    public static class logronueve
    {
        public static int inspect { get; set; }
    }
    internal Transform thisTransform;
    public Rigidbody2D rig;
    public SpriteRenderer sr;
    Animator animatorController;

    // The movement speed of the object
    public float moveSpeed = 0.2f;

    // A minimum and maximum time delay for taking a decision, choosing a direction to move in
    public Vector2 decisionTime = new Vector2(1, 4);
    internal float decisionTimeCount = 0;

    // The possible directions that the object can move int, right, left, up, down, and zero for staying in place. I added zero twice to give a bigger chance if it happening than other directions
    internal Vector3[] moveDirections = new Vector3[] { Vector3.right, Vector3.left, Vector3.up, Vector3.down, Vector3.zero};
    internal int currentMoveDirection;

    // Use this for initialization
    void Start()
    {
        // Cache the transform for quicker access
        thisTransform = this.transform;
        // Set a random time delay for taking a decision ( changing direction,or standing in place for a while )
        decisionTimeCount = Random.Range(decisionTime.x, decisionTime.y);

        // Choose a movement direction, or stay in place
        ChooseMoveDirection();

        animatorController = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        // Move the object in the chosen direction at the set speed
        Vector3 direction = moveDirections[currentMoveDirection];
        float xDir = direction.x;
        float yDir = direction.y;

        thisTransform.position += direction * Time.deltaTime * moveSpeed;

        if (currentMoveDirection == 0)
        {
            UpdateAnimation(PlayerAnimation.right);
        }
        else if (currentMoveDirection == 1)
        {
            UpdateAnimation(PlayerAnimation.left);
        }
        else if (currentMoveDirection == 2)
        {
            UpdateAnimation(PlayerAnimation.up);
        }
        else if (currentMoveDirection == 3)
        {
            UpdateAnimation(PlayerAnimation.down);
        }
        else if (currentMoveDirection == 4)
        {
            UpdateAnimation(PlayerAnimation.idle);
            if(logronueve.inspect < 1000){
                logronueve.inspect++;
            }
            else if(logronueve.inspect == 1000){
                Achievements.Instance.logronueve();
                logronueve.inspect++;
            }
        }

        if (decisionTimeCount > 0) decisionTimeCount -= Time.deltaTime;
        else
        {
            // Choose a random time delay for taking a decision ( changing direction, or standing in place for a while )
            decisionTimeCount = Random.Range(decisionTime.x, decisionTime.y);

            // Choose a movement direction, or stay in place
            ChooseMoveDirection();
        }
    }

    void ChooseMoveDirection()
    {
        // Choose whether to move sideways or up/down
        currentMoveDirection = Mathf.FloorToInt(Random.Range(0, moveDirections.Length));
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (currentMoveDirection == 0)
        {
            currentMoveDirection = 1;
            UpdateAnimation(PlayerAnimation.left);
        }
        else if(currentMoveDirection == 1)
        {
            currentMoveDirection = 0;
            UpdateAnimation(PlayerAnimation.right);
        }
        else if (currentMoveDirection == 2)
        {
            currentMoveDirection = 3;
            UpdateAnimation(PlayerAnimation.down);
        }
        else if (currentMoveDirection == 3)
        {
            currentMoveDirection = 2;
            UpdateAnimation(PlayerAnimation.up);
        }
        Vector3 direction = moveDirections[currentMoveDirection];
        float xDir = direction.x;
        float yDir = direction.y;

        thisTransform.position += direction * Time.deltaTime * moveSpeed;
    }

    void UpdateAnimation(PlayerAnimation nameAnimation)
    {
        switch (nameAnimation)
        {
            case PlayerAnimation.right:
                animatorController.SetBool("isWalkingR", true);
                animatorController.SetBool("isWalkingL", false);
                animatorController.SetBool("isUp", false);
                animatorController.SetBool("isDown", false);
                break;
            case PlayerAnimation.left:
                animatorController.SetBool("isWalkingR", false);
                animatorController.SetBool("isWalkingL", true);
                animatorController.SetBool("isUp", false);
                animatorController.SetBool("isDown", false);
                break;
            case PlayerAnimation.up:
                animatorController.SetBool("isWalkingR", false);
                animatorController.SetBool("isWalkingL", false);
                animatorController.SetBool("isUp", true);
                animatorController.SetBool("isDown", false);
                break;
            case PlayerAnimation.down:
                animatorController.SetBool("isWalkingR", false);
                animatorController.SetBool("isWalkingL", false);
                animatorController.SetBool("isUp", false);
                animatorController.SetBool("isDown", true);
                break;
            case PlayerAnimation.idle:
                animatorController.SetBool("isWalkingR", false);
                animatorController.SetBool("isWalkingL", false);
                animatorController.SetBool("isUp", false);
                animatorController.SetBool("isDown", false);
                break;
        }
    }

    public enum PlayerAnimation
    {
        right, left, up, down, idle
    }
}