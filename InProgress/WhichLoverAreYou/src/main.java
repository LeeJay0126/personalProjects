import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class main {

    Scanner in = new Scanner(System.in);
    Management management = new Management();
    ArrayList<Account> userList = management.returnUserList();
    Account loggedInUser = null;

    public static void main(String[] args) throws IOException {

        main o = new main();

        o.boot();

        System.out.println("Welcome to WhichLoverAreYou!");
        o.loginMenu();



    }

    public void loginMenu() throws IOException {
        int login = 0;

        while(!(login == 1 || login == 2)) {
            System.out.println("Please enter 1 to create an account \n" +
                    "Enter 2 to log in.");
            login = in.nextInt();

            if(login != 1 || login != 2){
                System.out.println("Please enter a 1 or 2 according to the direction");
            }
        }

        if(login == 2){
            createAccount();
        }else{
            while(loggedInUser == null){
                loggedInUser = login();
            }
        }
    }

    public Account login(){

        System.out.println("Enter Your ID: ");
        String id = in.nextLine();

        System.out.println("Enter Your Pw");
        String PW = in.nextLine();

        for(int i = 0; i < userList.size(); i++){
            if(userList.get(i).getId() == id){
                if(userList.get(i).getPw() == PW){
                    return userList.get(i);
                }else{
                    System.out.println("Wrong password. Please try again");
                }
            }else{
                System.out.println("Wrong ID. Please try again.");
            }
        }

        return null;

    }

    public void createAccount() throws IOException {

        System.out.println("Enter your full name including your first, middle, and last name: ");
        String name = in.nextLine();

        System.out.println("Enter your email address: ");
        String email = in.nextLine();

        boolean idValidation = false;
        String id = "";
        while(idValidation == false) {
            System.out.println("Enter your desired id: ");
            id = in.nextLine();

            for(int i = 0; i < management.returnUserList().size(); i ++){
                if(management.returnUserList().get(i).getId() == id){
                    System.out.println("ID is already in use. Please try a different ID.");
                }else{
                    idValidation = true;
                }
            }
        }

        System.out.println("Enter your desired pw: ");
        String PW = in.nextLine();

        Account newUser = new Account(id, PW, name, email);
        addAccount(newUser);

    }

    public void addAccount(Account newUser) throws IOException {

        management.addUser(newUser);

        FileWriter writer = new FileWriter("userHistory.csv");
        writer.append(newUser.getId());
        writer.append(",");
        writer.append(newUser.getPw());
        writer.append(",");
        writer.append(newUser.getName());
        writer.append(",");
        writer.append(newUser.getEmail());
        writer.append(",");
        writer.append("\n");

        writer.flush();
        writer.close();

    }

    public void boot() throws IOException {

        File userHistory = new File("userHistory.csv");
        if(userHistory.exists() && !userHistory.isDirectory()){
            csvReader(userHistory);
        }

        adminAccount adminJay = new adminAccount("topaz1103", "Topaz1103@", "Jay Seung Yeon Lee", "topaz9889@gmail.com");
        if(!(management.returnUserList().contains("topaz1103"))){
            management.addUser(adminJay);
        }

    }

    public void csvReader(File file) throws IOException {

        FileInputStream ft = new FileInputStream(file);
        DataInputStream dt = new DataInputStream(ft);

        BufferedReader br = new BufferedReader(new InputStreamReader(dt));
        String line;

        System.out.println("a");

        while((line = br.readLine()) != null){
            String[] temp = line.split(",");
            if(temp[0] != "") {
                Account account = new Account(temp[0], temp[1], temp[2], temp[3]);
                management.addUser(account);
            }
        }

    }

}
