import java.io.*;
import java.rmi.*;
public class Client
{
	public static void main(String argv[])
	{
		try
		{
			String registryURL = "rmi://193.20.150.114:4200/FileServer";
			FileInt fi = (FileInt) Naming.lookup(registryURL);
			byte[] filedata = fi.sendFile("p.jpg");
			File file = new File("p222.jpg");
			BufferedOutputStream output = new BufferedOutputStream(new FileOutputStream(file.getName()));
			output.write(filedata,0,filedata.length);
			output.flush();
			output.close();
		}
		catch(Exception e)
		{
			System.err.println("FileServer exception: "+ e.getMessage());
			e.printStackTrace();
		}
	}
}