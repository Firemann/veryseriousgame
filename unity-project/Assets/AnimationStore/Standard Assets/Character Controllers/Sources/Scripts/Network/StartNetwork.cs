using UnityEngine;
using System.Collections;
using vsm.unity;
using System.Threading;

public class StartNetwork : MonoBehaviour {
	
	public bool server { get; set; }
	public int listenPort = 25000;
	public string remoteIP = "127.0.0.1";
	public VSUnityClientI unityClient;
	
	void Awake(){
		DontDestroyOnLoad (this);
	}
	
	// Use this for initialization
	void Start () {
		if (server) {
			Network.InitializeServer(32, listenPort, !Network.HavePublicAddress());
			GameObject[] objects = FindObjectsOfType(typeof(GameObject)) as GameObject[];
			foreach (GameObject go in objects) {
				go.SendMessage("OnNetworkLoadedLevel", SendMessageOptions.DontRequireReceiver);
			}
			unityClient = new VSUnityClientI();
		}
		else {
			Network.Connect(remoteIP,listenPort);
		}
		Application.LoadLevel("destroyed_city");
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	
	void OnPlayerConnected(NetworkPlayer player)
	{
		if (server)	{
			print("Player Connected !");
		}
	}
	
	void OnLevelWasLoaded() {
		if (Application.loadedLevelName == "mainMenu") {
			Destroy(this.gameObject);
		}
		// Notify our objects that the level and the network are ready
		GameObject[] objects = FindObjectsOfType(typeof(GameObject)) as GameObject[];
		foreach (GameObject go in objects) {
			go.SendMessage("OnNetworkLoadedLevel", SendMessageOptions.DontRequireReceiver);
		}
			print("Coucou hibou");
		StartCoroutine(SpawnPlayer());
	}
	
	IEnumerator SpawnPlayer() {
		if(!server) {
			yield return new WaitForSeconds(3);
		}
	}
	
}
