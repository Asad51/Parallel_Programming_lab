import java.rmi.*;
import java.rmi.server.*;

public class InterfaceImp extends UnicastRemoteObject implements Adder {

   	InterfaceImp() throws RemoteException {
   		super();
    }
    
    public void add(int x, int y) throws RemoteException {
    	System.out.println(x+y);
    }
    
}