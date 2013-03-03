using UnityEngine;
using System.Collections;
using vsm.network;

public class NetworkTest : MonoBehaviour {

	// Use this for initialization
	void Start () {
        (new VSNetworkManager()).main(new string[0]);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
