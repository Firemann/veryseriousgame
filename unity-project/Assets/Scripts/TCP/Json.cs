using UnityEngine;
using System.Collections;
using JsonFx.Json;

public class Kikou {
	public int age;
	public string firstName, lastName;
	
	public Kikou(int age, string firstName, string lastName) {
		this.age = age;
		this.firstName = firstName;
		this.lastName = lastName;
	}
}

public class Json : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		Kikou k = new Kikou(18, "Benjamin", "FÜHRMANN");
		string s = JsonWriter.Serialize(k);
		print(s);
	}
}
