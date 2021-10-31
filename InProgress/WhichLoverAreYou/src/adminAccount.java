import java.util.ArrayList;

public class adminAccount extends Account{

    ArrayList<Account> users = Management.returnUserList();

    //admin account constructor
    public adminAccount(String id, String pw, String name, String email) {
        super(id, pw, name, email);
    }

    // views all accumulated users
    public void viewUsers(){
        for(int i = 0; i < users.size(); i++){
            System.out.println("name: " + users.get(i).getName() + " email: " + users.get(i).getEmail() + " ID: " + users.get(i).getId() + "PW: " + users.get(i).getPw());
        }
    }

    //bans a user from logging in until next boot
    public void banUsers(String id){
        Account ban = null;

        for(int i = 0; i < users.size(); i++){
            if(users.get(i).getId() == id){
                ban = users.get(i);
            }
        }

        if(ban != null){
            users.remove(ban);
        }
    }

}
