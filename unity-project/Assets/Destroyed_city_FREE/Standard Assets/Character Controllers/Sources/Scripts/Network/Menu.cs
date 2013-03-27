using UnityEngine;
using System.Collections;

public class Menu : MonoBehaviour {
	
	public GameObject networkMaster; // Prefab

	private GameObject instantiatedMaster; //Prefab instancié
	private StartNetwork scriptStartNet;
	
	private string serverIP  = "127.0.0.1";
	private int serverPort = 25000;
	
	public void Start() {
        Loom l = Loom.Current;
	}
	
	public void OnGUI() {
		int menuSizeX = 460;
		int menuSizeY = 115;
		float menuPosX = 20f;
		float menuPosY = (Screen.height/2 - menuSizeY/2);
		Rect mainMenu = new Rect(menuPosX, menuPosY, menuSizeX, menuSizeY);
		int sizeButtonX = 250;
		int sizeButtonY = 30;
		
		//Le menu de base
		GUI.BeginGroup(mainMenu, "");
		GUI.Box(new Rect(0,0,menuSizeX, menuSizeY), "");
		
		//La demande de champs d'ip pour rejoindre un serveur
		serverIP = GUI.TextField(new Rect(sizeButtonX + 30, 60, 120, 30), serverIP, 40);
		
		if (GUI.Button(new Rect(10, 20, sizeButtonX, sizeButtonY), "Create server")) {
			//Création du serveur
			instantiatedMaster = Instantiate(networkMaster, Vector3.zero, Quaternion.identity) as GameObject;
			scriptStartNet = instantiatedMaster.GetComponent("StartNetwork") as StartNetwork;
			scriptStartNet.server = true;
			scriptStartNet.listenPort = serverPort;
			scriptStartNet.remoteIP = serverIP;
		}
		if (GUI.Button(new Rect(10, 60, sizeButtonX, sizeButtonY), "Join server")) {
			//Rejoindre serveur
			instantiatedMaster = Instantiate(networkMaster, Vector3.zero, Quaternion.identity) as GameObject;
			scriptStartNet = instantiatedMaster.GetComponent("StartNetwork") as StartNetwork;
			scriptStartNet.server = false;
			scriptStartNet.listenPort = serverPort;
			scriptStartNet.remoteIP = serverIP;
		}
		GUI.EndGroup();
	}

}
