using UnityEngine;
using System.Collections;

public class MainCamera : MonoBehaviour {

public GameObject soldier;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		transform.LookAt(soldier.transform.Find("smoothWorldPosition/soldierSkeleton/Bip01/Bip01 Pelvis"));
		transform.Translate (new Vector3 (10,10,10));
	}
}
