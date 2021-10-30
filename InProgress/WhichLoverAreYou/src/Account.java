public class Account {
    private String id;
    private String pw;
    private String name;
    private String email;
    private String accessLevel;

    public Account(String s, String id, String pw, String name, String email){
            this.id = id;
            this.pw = pw;
            this.name = name;
            this.email = email;
            this.accessLevel = "CLIENT";
    }

    public String getId(){
        return id;
    }

    public String getPw(){
        return pw;
    }

    public String getEmail(){
        return email;
    }

    public String getName(){
        return name;
    }

    public void admin(){
        this.accessLevel = "ADMIN";
    }

}
