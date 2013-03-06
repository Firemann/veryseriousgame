package vsm.network;

import java.nio.channels.AlreadyConnectedException;
import java.util.ArrayList;
import java.util.List;

import javax.swing.SwingUtilities;

import unityView.UnityView;
import Ice.Current;
import Ice.Object;
import Ice.ObjectFactory;

@SuppressWarnings("serial")
public class VSServerI extends VSServer {
		
	private List<VSClientPrx> clientsList;
	private UnityView unityView;

	public VSServerI(UnityView unityView) {
		clientsList = new ArrayList<>();
		this.unityView = unityView;
	}

	@Override
	public void register(final VSClientPrx client, Current __current)
			throws vsm.network.AlreadyConnectedException {
		if(clientsList.contains(client))
			throw new AlreadyConnectedException();
		clientsList.add(client);
		if(client.getClientType() == ClientType.UNITY) {
			final VSUnityClientPrx azerty = VSUnityClientPrxHelper.checkedCast(client);
			SwingUtilities.invokeLater(new Runnable() {
				
				@Override
				public void run() {
					unityView.setProxy(azerty);
				}
			});
		}
	}
	
    public static Ice.ObjectFactory ice_factory() {
       return new ObjectFactory() {
			
			@Override
			public Object create(String type) {
		        if (type.equals(VSServer.ice_staticId()) )
		            return new VSServerI(null);
		        else
		        	return null;
			}

			@Override
			public void destroy() {
			}
		};
    }

}
