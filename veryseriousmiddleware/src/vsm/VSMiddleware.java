package vsm;

import vsm.network.VSServerI;
import Ice.Application;
import Ice.EncodingVersion;
import Ice.ObjectAdapter;

/**
 * The main class of the VSM Program, managing the Ice initialization
 * @author Benjamin FÜHRMANN
 *
 */
public class VSMiddleware extends Application {
	
	private VSServerI server;

	public VSMiddleware(VSServerI server) {
		this.server = server;
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				VSMiddleware.this.main("Very Serious Middleware", new String[0]);
			}
		}).start();
	}
	
	@Override
	public int run(String[] args) {
		// Manage correct ending of the program for whatever issue 
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
		ObjectAdapter adapter = communicator().createObjectAdapterWithEndpoints("VerySeriousMiddleware", "default -p 5432");
		
//		// Add all the object factories to the Ice communicator
//		for(Class<?> c:ICE_OBJECTS) {
//			try {
//				communicator().addObjectFactory((ObjectFactory) (c.getMethod("ice_factory").invoke(null)), (String) (c.getMethod("ice_staticId").invoke(null)));
//			} catch (IllegalAccessException | IllegalArgumentException
//					| InvocationTargetException | NoSuchMethodException
//					| SecurityException e) {
//				e.printStackTrace();
//			}
//		}
		
		// Creating all the objects the client will use
		adapter.add(server, communicator().stringToIdentity("VerySeriousMiddleware"));
		
		// Allow clients requests and wait until we are done
		adapter.activate();
		communicator().waitForShutdown();
		System.exit(0);
		return 0;
	}

}
