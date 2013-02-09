package model;

public class Kikou {

	public Kikou(int age, String firstName, String lastName) {
		super();
		this.age = age;
		this.firstName = firstName;
		this.lastName = lastName;
	}
	private int age;
	private String firstName, lastName;
	
	public String toString() {
		return "Kikou : " + firstName + " - " + lastName + " ! " + age;
	}
	
}
