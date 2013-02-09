package network.json;

import model.Kikou;

import com.google.gson.Gson;

public class Json {

	public static void main(String... args) {
		Gson gson = new Gson();
		Kikou k = new Kikou(21, "Florian", "GREFF");
		System.out.println(gson.toJson(k));
	}	
}
