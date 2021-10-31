import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class main {

    Scanner in = new Scanner(System.in);
    Account loggedInUser = null;
    private static adminAccount adminJay;

    public static void main(String[] args) throws IOException {

        main o = new main();
        Management manage = new Management();

        adminJay = new adminAccount("topaz1103", "Topaz1103@", "Jay Seung Yeon Lee", "topaz9889@gmail.com");
        o.boot(manage);

        if(!(manage.returnUserList().contains("topaz1103"))){
            manage.addUser(adminJay);
        }

        adminJay.viewUsers();

        System.out.println("Welcome to WhichLoverAreYou!");
        o.loginMenu(manage);



    }

    public void loginMenu(Management manage) throws IOException {
        int login = 0;

        while(!(login == 1 || login == 2)) {
            System.out.println("Please enter 1 to create an account \n" +
                    "Enter 2 to log in.");
            login = Integer.parseInt(in.nextLine());

            if(login != 1 || login != 2){
                System.out.println("Please enter a 1 or 2 according to the direction");
            }
        }

        if(login == 1){
            createAccount(manage);
        }else{
            while(loggedInUser == null){
                loggedInUser = login(manage);
            }
        }
    }

    public Account login(Management manage){

        System.out.println("Enter Your ID: ");
        String id = in.nextLine();

        ArrayList<Account> userList = manage.returnUserList();

        for(int i = 0; i < manage.returnUserList().size(); i++){

            if(userList.get(i).getId() == id){
                System.out.println("Enter Your PW: ");
                String PW = in.nextLine();
                if(userList.get(i).getPw() == PW){
                    return userList.get(i);
                }else{
                    System.out.println("Wrong password. Please try again");
                }
            }
        }

        System.out.println("Wrong ID. Please try again.");

        return null;

    }

    public void createAccount(Management manage) throws IOException {

        System.out.println("Enter your full name including your first, middle, and last name: ");
        String name = in.nextLine();

        System.out.println("Enter your email address: ");
        String email = in.nextLine();

        boolean idValidation = false;
        String id = "";
        while(idValidation == false) {
            System.out.println("Enter your desired id: ");
            id = in.nextLine();

            for(int i = 0; i < manage.returnUserList().size(); i ++){
                if(manage.returnUserList().get(i).getId() == id){
                    System.out.println("ID is already in use. Please try a different ID.");
                }else{
                    idValidation = true;
                }
            }
        }

        System.out.println("Enter your desired pw: ");
        String PW = in.nextLine();

        Account newUser = new Account(id, PW, name, email);
        addAccount(newUser, manage);

    }

    public void addAccount(Account newUser, Management manage) throws IOException {

        manage.addUser(newUser);

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

    public void boot(Management manage) throws IOException {

        File userHistory = new File("userHistory.csv");
        if(userHistory.exists() && !userHistory.isDirectory()){
            csvReader(userHistory, manage);
        }

    }

    public void csvReader(File file, Management manage) throws IOException {

        FileInputStream ft = new FileInputStream(file);
        DataInputStream dt = new DataInputStream(ft);

        BufferedReader br = new BufferedReader(new InputStreamReader(dt));
        String line;

        while((line = br.readLine()) != null){
            String[] temp = line.split(",");
            if(temp[0] != "") {
                Account account = new Account(temp[0], temp[1], temp[2], temp[3]);
                manage.addUser(account);
            }
            System.out.println("a");
        }

    }

}
