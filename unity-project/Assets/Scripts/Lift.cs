using UnityEngine;
using System.Collections;

public class Lift : MonoBehaviour {
	
	public bool isDown;
	private bool isMoving;
	public float latence;
	public float upPosition, downPosition;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	
	IEnumerator OnSwitched(){
		if (!isMoving){
			isMoving=true;
			
			if (isDown){
				//monter
				while (transform.localPosition.y < upPosition)
				{
					yield return new WaitForSeconds(latence);
					Vector3 v = transform.position;
					transform.position.y += 0.1;
				}
				
				isDown=false;
			}
			
			else{
				//descendre
				while (transform.localPosition.y < upPosition)
				{
					yield return new WaitForSeconds(latence);
					transform.position.y -= 0.1;
				}
				
				isDown=true;
				
			}
			
			isMoving=false;
		}
	}
	
	void OnTriggerStay(Collider col){
		if (col.transform.name=="ActionField"){
			if (col.transform.root.networkView.isMine){
				if 	(Input.GetKeyDown (KeyCode.E) || Input.GetKeyDown (KeyCode.Return)){
					OnSwitched ();	
				}
			}
		}
	}
	
	
	
}
