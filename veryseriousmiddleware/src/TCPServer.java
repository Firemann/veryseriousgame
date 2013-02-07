import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;


public class TCPServer {
	
	   public static void main(String argv[]) throws Exception {
	         String clientSentence;
	         //String capitalizedSentence;
	         ServerSocket welcomeSocket = new ServerSocket(10000);

        	 System.out.println("lol");
	            Socket connectionSocket = welcomeSocket.accept();
	         while(true)
	         {
	            BufferedReader inFromClient =
	               new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
	            System.out.println("lal1");
	            //DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
	            clientSentence = inFromClient.readLine();
	            System.out.println("lal2");
	            System.out.println("Received: " + clientSentence);
	            //capitalizedSentence = clientSentence.toUpperCase() + '\n';
	            //outToClient.writeBytes(capitalizedSentence);
	         }
	         
	      }
	}