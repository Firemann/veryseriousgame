using UnityEngine;
using System.Collections;

public class GroundAnalyst : MonoBehaviour {
	
	private Cuby scriptCuby ;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	
	void OnTriggerEnter(Collider col){
		if (col.gameObject.name=="Terrain") {//si l'objet qui traverse le GroundAnalyst s'appelle Terrain	
			scriptCuby = transform.root.GetComponent ("Cuby") as Cuby;
			scriptCuby.canJump=true;
		}
	}
}
