package vsm.network;

import java.nio.channels.AlreadyConnectedException;
import java.util.ArrayList;
import java.util.List;

import Ice.Current;
import Ice.Object;
import Ice.ObjectFactory;

@SuppressWarnings("serial")
public class VSServerI extends VSServer {
		
	private List<VSClientPrx> clientsList;

	public VSServerI() {
		clientsList = new ArrayList<>();
	}

	@Override
	public void register(VSClientPrx client, Current __current)
			throws vsm.network.AlreadyConnectedException {
		if(clientsList.contains(client))
			throw new AlreadyConnectedException();
		clientsList.add(client);
		System.out.println("Registered");
		System.out.println("New Client connected : " + client.getClientType());
	}
	
    public static Ice.ObjectFactory ice_factory() {
       return new ObjectFactory() {
			
			@Override
			public Object create(String type) {
		        if (type.equals(VSServer.ice_staticId()) )
		            return new VSServerI();
		        else
		        	return null;
			}

			@Override
			public void destroy() {
			}
		};
    }

}
