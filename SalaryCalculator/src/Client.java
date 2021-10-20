import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client implements Protocol {
    public static void main(String[] args) {
        new Client("localhost");
    }
    public Client(String host) {

        try (Socket socket = new Socket(host, Protocol.PORT)) {

            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out= new DataOutputStream(socket.getOutputStream());

            Calculate(in, out);
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
    public void Calculate(DataInputStream in,DataOutputStream out) throws IOException {
        Scanner fromUser = new Scanner(System.in);
        System.out.println("Enter 1 if you want to know your salary and taxes based on $/hr and hours of work per week or 2 if you already know your annual salary : ");
        int choice = fromUser.nextInt();

        out.writeInt(choice);
        out.flush();

        int command;
        double wage;
        double hours;
        double initialSalary;
        String result;
        int validator = 0;

        do{
            command = in.readInt();
            switch(command){
                case WAGES:
                    System.out.println("Enter your wage per hour : ");
                    wage = fromUser.nextDouble();
                    out.writeDouble(wage);
                    out.flush();
                    break;
                case HOURS:
                    System.out.println("Enter how many hours of work you do per week: ");
                    hours = fromUser.nextDouble();
                    out.writeDouble(hours);
                    out.flush();
                    break;
                case INITSALARY:
                    System.out.println("Enter your annual salary : ");
                    initialSalary = fromUser.nextDouble();
                    out.writeDouble(initialSalary);
                    out.flush();
                    break;
                case RESULT:
                    result = in.readUTF();
                    System.out.println(result);
                    out.writeInt(DONE);
                    out.flush();
                case DONE:
                    System.out.println("Thank you for using Salary/Tax Calculator!");
                    validator = 1;
            }

        } while(validator != 1);

    }
} 