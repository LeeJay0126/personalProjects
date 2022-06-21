import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Login {

    Scanner in = new Scanner(System.in);
    Account loggedInUser = null;

    public Login(){

    }

    public Account start() throws IOException {

        Management manage = new Management();

        //Admin Account;
        boot(manage);

        boolean valid = false;
        for (int i = 0; i < manage.returnUserList().size(); i++) {
            if ((manage.returnUserList().contains("topaz1103"))) {
                valid = true;
                break;
            }
        }

        System.out.println("Welcome to WhichLoverAreYou!");
        loginMenu(manage);

        return loggedInUser;

    }

    public void loginMenu(Management manage) throws IOException {
        int login = 0;

        while(!(login == 2)) {
            System.out.println("Please enter 1 to create an account \n" +
                    "Enter 2 to log in.");
            login = Integer.parseInt(in.nextLine());

            if(login != 1 && login != 2){
                System.out.println("Please enter a 1 or 2 according to the direction");
            }else if (login == 1) {
                createAccount(manage);
            }
        }

        if(login == 2) {
            while (loggedInUser == null) {
                loggedInUser = login(manage);
            }
        }
    }

    public Account login(Management manage){

        System.out.println("Enter Your ID: ");
        String id = in.nextLine();

        ArrayList<Account> userList = manage.returnUserList();

        System.out.println(manage.returnUserList().size());

        for(int i = 0; i < manage.returnUserList().size(); i++){

            if(userList.get(i).getId().equals(id)){
                System.out.println("Enter Your PW: ");
                String PW = in.nextLine();
                if(userList.get(i).getPw().equals(PW)){
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

    public void reload(Management manage, FileWriter writer) throws IOException{

        for(int i = 0; i < manage.returnUserList().size(); i++){
            writer.append(manage.returnUserList().get(i).getId());
            writer.append(",");
            writer.append(manage.returnUserList().get(i).getPw());
            writer.append(",");
            writer.append(manage.returnUserList().get(i).getName());
            writer.append(",");
            writer.append(manage.returnUserList().get(i).getEmail());
            writer.append(",");
            writer.append("\n");

            writer.flush();
        }

    }

    public void addAccount(Account newUser, Management manage) throws IOException {

        manage.addUser(newUser);

        FileWriter writer = new FileWriter("userHistory.csv");
        reload(manage,writer);

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
        }

    }

}

