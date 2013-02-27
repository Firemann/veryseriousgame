package vsm.network;

import java.nio.channels.AlreadyConnectedException;
import java.util.ArrayList;
import java.util.List;

import verySeriousNetwork.VSClientPrx;
import verySeriousNetwork._VSServerDisp;
import Ice.Current;

@SuppressWarnings("serial")
public class VSServerI extends _VSServerDisp {
	
	private List<VSClientPrx> clientsList;

	public VSServerI() {
		clientsList = new ArrayList<>();
	}
	
	@Override
	public void register(VSClientPrx client, Current __current)
			throws AlreadyConnectedException {
		if(clientsList.contains(client))
			throw new AlreadyConnectedException();
		clientsList.add(client);
	}

}
