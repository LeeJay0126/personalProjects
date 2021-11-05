import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class main {

    Scanner in = new Scanner(System.in);
    private static adminAccount adminJay;

    public static void main(String[] args) throws IOException {

        main o = new main();
        Login login = new Login();

        Account loggedInUser = login.start();

        System.out.println(loggedInUser.getName());

        ArrayList <String> questionList = new ArrayList<>();
        Questions questions = new Questions();
        questionList = questions.questionsIntializer();



    }


}