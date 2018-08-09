import java.io.*;
import java.rmi.*;
import java.rmi.registry.*;
import java.net.*;

public class Server{
	public static void main(String args[]){
		String registryURL;
		int portNum = 5000;
		try{
			InterfaceImp obj = new InterfaceImp();
			startRegistry(portNum);
			registryURL = "rmi://localhost:"+portNum+"/index";
			Naming.rebind(registryURL, obj);
			System.out.println("Server is ready.");
		}
		catch(Exception e){
			System.out.println(e);
		}
	}

	private static void startRegistry(int portNum) throws RemoteException{
		try{
			Registry registry = LocateRegistry.getRegistry(portNum);
			registry.list();
		}
		catch(RemoteException ex){
			System.out.println("Can't be located at " + portNum);
			Registry registry = LocateRegistry.getRegistry(portNum);
			System.out.println("Created at " + portNum);
		}
	}
}
