import java.io.*;
import java.rmi.*;
import java.rmi.registry.*;
import java.net.*;

import java.rmi.Naming;

public class Server{
	public static void main(String args[]){
		String portNum = "4200";
		String registryURL = "rmi://193.20.150.114:" + portNum + "/FileServer";
		try{
			Registry registry = LocateRegistry.getRegistry(Integer.parseInt(portNum));
			FileImp fs = new FileImp();
			Naming.rebind(registryURL, fs);
			System.out.println("Server is ready.");
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}