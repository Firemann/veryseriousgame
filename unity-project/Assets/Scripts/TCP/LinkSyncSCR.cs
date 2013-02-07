using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;
using System.Security.Permissions;
 
public class LinkSyncSCR : MonoBehaviour {
	public Connector test=new Connector();
	string lastMessage;
	public Transform PlayerCoord;
 
	void Start () 
	{
		Debug.Log(test.fnConnectResult("127.0.0.1",10000,System.Environment.MachineName));
		if (test.res !="")
		{
			Debug.Log(test.res);
		}
 
	}
	void Update () 
	{
		if (Input.GetKeyDown ("space")) 
		{
	        Debug.Log ("space key was pressed");
			test.fnPacketTest("space key was pressed");
		}
 
		if (Input.GetKeyDown ("escape")) 
		{
	        Debug.Log ("escape key was pressed");
			test.fnPacketTest("escape key was pressed");
		}
		if (test.strMessage !="JOIN")
		{
			if (test.res != lastMessage)
			{
				Debug.Log(test.res);
				lastMessage=test.res;
			}
		}
		//test.fnPacketTest(PlayerCoord.position[0]+","+PlayerCoord.position[1]+","+PlayerCoord.position[2]);
	}
 
	void OnApplicationQuit (){
		try{test.fnDisconnect();}
		catch{}
	}
}
