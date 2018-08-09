import java.rmi.*;
import java.io.*;
import java.rmi.server.*;
import java.rmi.server.UnicastRemoteObject;

public class FileImp extends UnicastRemoteObject implements FileInt{
	private String name;
	public FileImp() throws RemoteException 
	{
		super();
		///name = s;
	}

	public byte[] sendFile(String fileName) throws RuntimeException{
		try
		{
			File file = new File(fileName);
			byte buffer[] = new byte[(int)file.length()];
			BufferedInputStream input = new BufferedInputStream(new FileInputStream(fileName));
			input.read(buffer,0,buffer.length);
			input.close();
			return(buffer);
		}
		catch(Exception e)
		{
			System.out.println("FileImpl: " + e.getMessage());
			e.printStackTrace();
			return(null);
		}
	}
}