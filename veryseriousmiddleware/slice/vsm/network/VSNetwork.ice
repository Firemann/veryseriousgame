module verySeriousNetwork {

	enum ClientType {
		UNITY
	};

	interface VSClient {
		idempotent ClientType getClientType();
	};
	
	exception AlreadyConnectedException {
		string reason;
	};
	

	interface VSServer {
		void register(VSClient *client) throws AlreadyConnectedException;
	};

};
