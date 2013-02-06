using UnityEngine;
using System.Collections;

public class Weapon : MonoBehaviour {
	
	public GameObject projectile;
	
	// Use this for initialization
	void Start () {
	
	}
	
	void Awake(){// pour ne pas activer l'arme de l'ennemi en même temps
		if (!networkView.isMine)
			Destroy (this);
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.Mouse0))
			Shoot ();
	}
	
	void Shoot(){
		GameObject objet= Network.Instantiate (projectile, transform.position, transform.rotation, 0) as GameObject;
		objet.rigidbody.velocity = transform.TransformDirection (Vector3.forward * 40);
	}
}
