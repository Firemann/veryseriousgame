using UnityEngine;
using System.Collections;

public class Cuby : MonoBehaviour {
	
	private float vitesse = 0.05f;

	// Use this for initialization
	void Start () {
	
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
  
		if ( Input.GetKeyDown(KeyCode.Space) ) //le saut
			rigidbody.AddForce(Vector3.up * 350);
	}
}
