package vsm;

import java.lang.reflect.InvocationTargetException;

import unityView.UnityView;
import vsm.network.VSServer;
import vsm.network.VSServerI;
import Ice.Application;
import Ice.ObjectAdapter;
import Ice.ObjectFactory;

/**
 * The main class of the VSM Program, managing the Ice initialization
 * @author Benjamin FÜHRMANN
 *
 */
public class VSMiddleware extends Application {
	
	/**
	 * List of all VSM classes implemented by the server.
	 * You have to add to the array any VSM class used with ice to automatically add the factory to the communicator
	 * Moreover, don't forget to overwrite the "ice_factory" method of this object to create the correct factory
	 */
	//private final static Class<?> ICE_OBJECTS[] = {VSServerI.class};

	public static void main(String... args) {
		VSMiddleware vsm = new VSMiddleware();
		int status = vsm.main("Very Serious Middleware", args);
		System.exit(status);
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
		ObjectAdapter adapter = communicator().createObjectAdapterWithEndpoints("VerySeriousMiddleware", "default -p 10000");
		
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
		VSServer server = new VSServerI(new UnityView());
		adapter.add(server, communicator().stringToIdentity("VerySeriousMiddleware"));
		
		// Allow clients requests and wait until we are done
		adapter.activate();
		communicator().waitForShutdown();
		return 0;
		
	}

}
