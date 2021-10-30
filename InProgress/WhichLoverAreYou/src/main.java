import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class main {

    Scanner in = new Scanner(System.in);
    Management management = new Management();

    public void main(String[] args) throws IOException {

        boot();
        

    }

    public void boot() throws IOException {

        File userHistory = new File("userHistory.csv");
        if(userHistory.exists() && !userHistory.isDirectory()){
            csvReader(userHistory);
        }
    }

    public void csvReader(File file) throws IOException {

        FileInputStream ft = new FileInputStream(file);
        DataInputStream dt = new DataInputStream(ft);

        BufferedReader br = new BufferedReader(new InputStreamReader(dt));
        String line;

        while((line = br.readLine()) != null){
            String[] temp = line.split(",");
            Account account = new Account(temp[0], temp[1], temp[2], temp[3], temp[4]);
            management.addUser(account);
        }

    }

}
