import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Protocol{

    public static void main(String[] args) throws IOException{

        ServerSocket server = new ServerSocket(PORT);
        while(true){

            Socket s = server.accept();
            System.out.println("Client accepted");


        }

    }

}

class Calculator extends Thread implements Protocol{

    private Socket client;
    private DataInputStream in;
    private DataOutputStream out;
    private int hours = 0;
    private int wage = 0;

    public Calculator(Socket client){
        this.client = client;
    }

    public void run(){

        try{
            in = new DataInputStream(client.getInputStream());
            out = new DataOutputStream(client.getOutputStream());
            doService();
        } catch (IOException exception) {
            exception.printStackTrace();
        }finally{
            try{
                client.close();
            }catch(IOException e){
                e.printStackTrace();
            }
        }

    }

    private void doService() throws IOException{

        try{

        }

    }

}
