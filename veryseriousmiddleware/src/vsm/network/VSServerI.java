package vsm.network;

import java.nio.channels.AlreadyConnectedException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.Map.Entry;

import vsm.VSVector3;
import vsm.networksimulator.VSNetworkSimulatorPrx;
import vsm.networksimulator.VSNetworkSimulatorPrxHelper;
import vsm.networksimulator.VSNodePrx;
import vsm.networksimulator.VSNodeType;
import vsm.unity.VSSoldierPrx;
import vsm.unity.VSUnityPrx;
import vsm.unity.VSUnityPrxHelper;
import Ice.Current;

@SuppressWarnings("serial")
public class VSServerI extends VSServer {
		
	public class Entity {
		private VSSoldierPrx soldier;
		private VSNodePrx node;
		
		public Entity(VSSoldierPrx soldier, VSNodePrx node) {
			super();
			this.soldier = soldier;
			this.node = node;
		}
		
		public VSSoldierPrx getSoldier() {
			return soldier;
		}
		
		public void setSoldier(VSSoldierPrx soldier) {
			this.soldier = soldier;
		}
		
		public VSNodePrx getNode() {
			return node;
		}
		
		public void setNode(VSNodePrx node) {
			this.node = node;
		}
		
		
	}
	
	private VSUnityPrx unityPrx;
	private VSNetworkSimulatorPrx nsPrx;
	private List<Entity> entityList;
	
	private List<VSServerListener> listeners;
	private List<VSNodePrx> antennaList;
	
	private int nodeCounter;
	private int refreshTime = 100;
	private Timer t;
	private int antennaCounter;
	
	public VSServerI() {
		entityList = new ArrayList<>();
		listeners = new ArrayList<>();
		antennaList = new ArrayList<>();
		nodeCounter = 0;
		
		t = new Timer();
		
		t.schedule(new TimerTask() {
			
			@Override
			public void run() {
				if(unityPrx != null && nsPrx != null)
					for(Entity e:entityList) {
						e.getNode().moveNode(e.getSoldier().getPosition());
					}
			}
		}, 0, refreshTime);
	}

	@Override
	public void register(final VSClientPrx client, Current __current)
			throws vsm.network.AlreadyConnectedException {
		ClientType type = client.getClientType();
		switch(type) {
		case UNITY:
			if(unityPrx != null)
				throw new AlreadyConnectedException();
			unityPrx = VSUnityPrxHelper.checkedCast(client);
			for (final VSServerListener l:listeners)
				new Thread(new Runnable() {
					
					@Override
					public void run() {
						l.unityClientConnected();
					}
				}).start();
			break;
		case NETWORKSIMULATOR:
			if(nsPrx != null)
				throw new AlreadyConnectedException();
			nsPrx = VSNetworkSimulatorPrxHelper.checkedCast(client);
			for (final VSServerListener l:listeners)
				new Thread(new Runnable() {
					
					@Override
					public void run() {
						l.networksimulatorClientConnected();
					}
				}).start();
			break;
		default:
			break;
		}
	}
	
	public void addListener(VSServerListener listener) {
		listeners.add(listener);
	}
	
	public void removeListener(VSServerListener listener) {
		listeners.remove(listener);
	}
	
	public VSNodePrx createAntenna(VSVector3 position) {
		if(nsPrx != null) {
			VSNodePrx node =nsPrx.createNode("Antenna" + antennaCounter++, position, VSNodeType.ANTENA);
			antennaList.add(node);
			for(VSServerListener l:listeners)
				l.antennaCreated(node);
			return node;
		}
		return null;
	}
	
	public void destroyAntena(VSNodePrx node) {
		if(nsPrx != null) {
			nsPrx.destroyNode(node);
			antennaList.remove(node);
			for(VSServerListener l:listeners)
				l.antennaDestroyed(node);
		}
	}
	
	public void instantiateSoldier() {
		VSSoldierPrx s = unityPrx.instantiateSoldier();
		VSNodePrx n = null;
		if(nsPrx != null)
			n = nsPrx.createNode("Node" + nodeCounter++, s.getPosition(), VSNodeType.CLIENT);
		entityList.add(new Entity(s, n));
		
		for(VSServerListener l:listeners)
			l.soldierAdded(s, n);
	}
	
	public void destroySoldier(Entity entity) {
		unityPrx.destroySoldier(entity.getSoldier());
		nsPrx.destroyNode(entity.getNode());
		
		for(VSServerListener l:listeners)
			l.soldierAdded(entity.getSoldier(), entity.getNode());
		
		entityList.remove(entity);
	}

	public List<Entity> getEntityList() {
		return entityList;
	}
	
	public List<VSNodePrx> getAntennaList() {
		return antennaList;
	}
	
//    public static Ice.ObjectFactory ice_factory() {
//       return new ObjectFactory() {
//			
//			@Override
//			public Object create(String type) {
//		        if (type.equals(VSServer.ice_staticId()) )
//		            return new VSServerI(null);
//		        else
//		        	return null;
//			}
//
//			@Override
//			public void destroy() {
//			}
//		};
//    }

}
