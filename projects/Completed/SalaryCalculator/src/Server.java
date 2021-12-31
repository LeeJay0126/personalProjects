import java.io.IOException;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.lang.Math;
import java.text.DecimalFormat;

public class Server implements Protocol {
    public static void main(String[] args) throws IOException {

        ServerSocket server = new ServerSocket(PORT);
        while(true){

            Socket s = server.accept();
            System.out.println("Client accepted");
            GameHandler game = new GameHandler(s);
            Thread t = new Thread(game);
            t.start();

        }
    }
}


class GameHandler extends Thread implements Protocol {

    private Socket client;
    private DataInputStream in;
    private DataOutputStream out;

    public GameHandler(Socket client) {

        this.client = client;
    }

    public void run() {

        try {
            in = new DataInputStream(client.getInputStream());
            out = new DataOutputStream(client.getOutputStream());
            doService();
        } catch (IOException exception) {
            exception.printStackTrace();
        } finally {
            try {
                client.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void doService() throws IOException {

        try {
            double hours;
            double wage;
            double initialSalary = 0;
            double federalTax;
            double provincialTax;
            double result;
            int command;

            command = in.readInt();
            if (command == 1) {

                out.writeInt(HOURS);
                out.flush();
                hours = in.readDouble();
                out.writeInt(WAGES);
                out.flush();
                wage = in.readDouble();

                initialSalary = (hours * wage) * 52;

            } else if (command == 2) {

                out.writeInt(INITSALARY);
                out.flush();
                initialSalary = in.readDouble();

            } else {
                System.out.println("sam");
                out.writeInt(DONE);
                out.flush();
            }

            System.out.println(initialSalary);

            if (initialSalary <= 49020) {
                federalTax = initialSalary * 0.15;
            } else if (initialSalary >= 49020 && initialSalary <= 98040) {
                federalTax = (initialSalary - 49020) * 0.205 + 49020 * 0.15;
            } else if (initialSalary >= 98040 && initialSalary <= 151978) {
                federalTax = 49020 * 0.15 + (initialSalary - 98040) * 0.26 + (98040 - 49020) * 0.205;
            } else if (initialSalary >= 151978 && initialSalary <= 2161511) {
                federalTax = 49020 * 0.15 + 0.26 + (98040 - 49020) * 0.205 + (151978 - 98040) * 0.26 + (initialSalary - 151978) * 0.29;
            } else {
                federalTax = 49020 * 0.15 + 0.26 + (98040 - 49020) * 0.205 + (151978 - 98040) * 0.26 + (216511 - 151978) * 0.29 + (initialSalary - 216511) * 0.33;
            }

            if (initialSalary <= 42184) {
                provincialTax = initialSalary * 0.0506;
            } else if (initialSalary >= 42184 && initialSalary <= 84369) {
                provincialTax = 42184 * 0.0506 + (initialSalary - 42184) * 0.077;
            } else if (initialSalary >= 84369 && initialSalary <= 96866) {
                provincialTax = 42184 * 0.0506 + (84369 - 42184) * 0.077 + (initialSalary - 84369) * 0.105;
            } else if (initialSalary >= 96866 && initialSalary <= 117623) {
                provincialTax = 42184 * 0.0506 + (84369 - 42184) * 0.077 + (96866 - 84369) * 0.105 + (initialSalary - 96866) * 0.1229;
            } else if (initialSalary >= 117623 && initialSalary <= 159483) {
                provincialTax = 42184 * 0.0506 + (84369 - 42184) * 0.077 + (96866 - 84369) * 0.105 + (117623 - 96866) * 0.1229 + (initialSalary - 117623) * 0.147;
            } else if (initialSalary >= 159483 && initialSalary <= 222420) {
                provincialTax = 42184 * 0.0506 + (84369 - 42184) * 0.077 + (96866 - 84369) * 0.105 + (117623 - 96866) * 0.1229 + (159483 - 117623) * 0.147 + (initialSalary - 159483) * 0.168;
            } else {
                provincialTax = 42184 * 0.0506 + (84369 - 42184) * 0.077 + (96866 - 84369) * 0.105 + (117623 - 96866) * 0.1229 + (159483 - 117623) * 0.147 + (222420 - 159483) * 0.168 + (initialSalary - 222420) * 0.205;
            }

            result = initialSalary - (federalTax + provincialTax);

            DecimalFormat df = new DecimalFormat("#.##");
            df.format(result);
            df.format(provincialTax);
            df.format(federalTax);
            df.format(initialSalary);

            out.writeInt(RESULT);
            out.writeUTF("Your federal tax is : " + federalTax + " and your provincial tax is : " + provincialTax + " and your total income after tax deduction from your initial salary " + initialSalary + " is " + result);
            out.flush();

        } catch (IOException exception) {
            getStackTrace();
        }

    }

}