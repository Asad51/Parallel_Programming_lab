import java.rmi.*;

public interface Adder extends Remote {
    public void add(int x, int y) throws RemoteException;
}