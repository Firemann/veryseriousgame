using UnityEngine;
using System.Collections;

public class StartNetwork : MonoBehaviour {
	
	public bool Server { get; set; }
	private int listenPort = 25000;
	private string remoteIP;
	
	void Awake(){
		DontDestroyOnLoad (this);
	}
	
	// Use this for initialization
	void Start () {
		if (Server) {
			Network.InitializeServer(32, listenPort, false);
			GameObject[] objects = FindObjectsOfType(typeof(GameObject)) as GameObject[];
			foreach (GameObject go in objects) {
				go.SendMessage("OnNetworkLoadedLevel", SendMessageOptions.DontRequireReceiver);
			}
		}
		else {
			Network.Connect (remoteIP,listenPort);	
		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
