using UnityEngine;
using System.Collections;

public class Cuby : MonoBehaviour {
	
	public GameObject playerCamera;
	private float vitesse = 0.2f;
	public bool canJump;

	// Use this for initialization
	void Start () {
		if (!networkView.isMine) //si ce perso ne m'appartient pas
		{
		 	Destroy(playerCamera);
		 	this.enabled = false;
		}
	}
	
	// Update is called once per frame
	void Update () {
		Deplacement();
	}
	
	private void Deplacement() {
		if ( Input.GetKey(KeyCode.Z) || Input.GetKey(KeyCode.UpArrow) )
			transform.Translate(Vector3.forward * vitesse);
		else if ( Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow) )
			transform.Translate(Vector3.back * vitesse);
		if ( Input.GetKey(KeyCode.Q) || Input.GetKey(KeyCode.LeftArrow) )
			transform.Translate(Vector3.left * vitesse);
		else if ( Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow) )
			transform.Translate(Vector3.right * vitesse);
  
		if ( Input.GetKeyDown(KeyCode.Space) && canJump){ //le saut
			rigidbody.AddForce(Vector3.up * 4000);
			canJump=false;
		}
	}
}
