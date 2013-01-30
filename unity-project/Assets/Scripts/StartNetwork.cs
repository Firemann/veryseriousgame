using UnityEngine;
using System.Collections;

public class StartNetwork : MonoBehaviour {
	
	public bool server { get; set; }
	public int listenPort = 25000;
	public string remoteIP = "127.0.0.1";
	public GameObject cuby, cubyInst;
	
	private GameObject[] spawners;
	private GameObject spawn;
	
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
		}
		else {
			Network.Connect(remoteIP,listenPort);
		}
		Application.LoadLevel("Level1");
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	
	void OnPlayerConnected(NetworkPlayer player)
	{
		if (server)	{
			print("Connecté !");
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
		
		spawners = GameObject.FindGameObjectsWithTag("Respawn") as GameObject[];
		int rand = Random.Range(0, spawners.Length);
		spawn = spawners[rand];
		StartCoroutine(SpawnPlayer());
		//cubyInst.transform.eulerAngles = new Vector3(0, 0, 90);
	}
	
	IEnumerator SpawnPlayer() {
		if(!server) {
			yield return new WaitForSeconds(3);
		}
		GameObject cubyInst = Network.Instantiate(cuby, spawn.transform.position, Quaternion.identity, 0) as GameObject;
	}
	
}
