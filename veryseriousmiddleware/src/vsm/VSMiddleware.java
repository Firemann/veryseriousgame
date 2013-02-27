package vsm;

import unityView.UnityView;
import Ice.Application;
import Ice.ObjectAdapter;

public class VSMiddleware extends Application {

	public static void main(String... args) {
		VSMiddleware vsm = new VSMiddleware();
		int status = vsm.main("Very Serious Middleware", args);
		System.exit(status);
	}
	
	@Override
	public int run(String[] args) {
		// Manage correct ending of the program for whatever origin 
		setInterruptHook(new Thread() {
			
			@Override
			public void run() {
				try {
					communicator().destroy();
				} catch(Ice.LocalException e) {
					e.printStackTrace();
				}
			}
			
		});
		shutdownOnInterrupt();
		
		// Adapter
		ObjectAdapter adapter = communicator().createObjectAdapterWithEndpoints("VerySeriousMiddleware", "default -p 10000");
		
		// Creating all the objects the client will use
		
		
		// View
		new UnityView();
		
		// Allow clients requests and wait until we are done
		adapter.activate();
		communicator().waitForShutdown();
		return 0;
		
	}

}
