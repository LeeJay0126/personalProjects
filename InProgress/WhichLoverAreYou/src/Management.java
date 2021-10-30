import java.util.ArrayList;

public class Management {
    ArrayList <Account> userList;

    public Management(){
        userList = new ArrayList<>();
    }

    public int addUser(Account user){
        if(!(userList.contains(user.getId()))) {
            this.userList.add(user);
            return 0;
        }else{
            return 1;
        }
    }

    public void makeAdmin(Account user){
        user.admin();
    }

    public String findPw(String id){

        for(int i = 0; i < userList.size();i++){
            if(id == userList.get(i).getId()){
                return userList.get(i).getPw();
            }
        }

        return "Please Check Your ID again.";

    }

    public String findId(String email, String name){
        for(int i = 0; i < userList.size();i++){
            if(email == userList.get(i).getEmail() && name == userList.get(i).getName()){
                return userList.get(i).getId();
            }
        }

        return "Please Check Your email address and name again.";
    }

    public String allAssociatedAccounts(String name){
        String result = "";

        for(int i = 0; i < userList.size(); i++){
            if(name == userList.get(i).getName()){
                result += name + " : " + userList.get(i).getEmail() + " " + userList.get(i).getId();
            }
        }

        if(result != ""){
            return result;
        }else{
            return "No account associated with that name. Please try again.";
        }

    }

}
