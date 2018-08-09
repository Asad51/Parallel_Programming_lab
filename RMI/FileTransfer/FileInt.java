import java.rmi.*;

public interface FileInt extends Remote  
{      
	public byte[] sendFile(String fileName) throws RemoteException;
}