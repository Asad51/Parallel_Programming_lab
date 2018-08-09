import java.io.*;
import java.rmi.*;
import java.net.*;

public class Client {
        
    public Client() {
    }
    
    public static void main(String[] args) {
        try{
        	int portNum = 5000;
            String registryURL;

            registryURL = "rmi://localhost:"+portNum+"/index";
            Adder obj = (Adder)Naming.lookup(registryURL);
            obj.add(34,35);
        }
        catch(Exception e){
        	System.out.println(e);
        }
    }
}
