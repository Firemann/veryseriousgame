using UnityEngine;
using System.Collections;
using vsm.network;
using System.Threading;

public class StartNetwork : MonoBehaviour {
	
	public bool server { get; set; }
	public int listenPort = 25000;
	public string remoteIP = "127.0.0.1";
	public GameObject soldier, soldierInst;
	
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
		Application.LoadLevel("destroyed_city");
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
		GameObject soldierInst = Network.Instantiate(soldier, spawn.transform.position, Quaternion.identity, 0) as GameObject;
        Transform t = soldierInst.transform;
        Loom.RunAsync(() =>
        {
            new VSNetworkManager(t).main(new string[0]);
        });
	}
	
}
