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

        System.out.println("These are some practice questions. Let's have a little test before we get into the real game.");

        ArrayList <String> questionList;
        Questions questions = new Questions();
        questionList = questions.questionsIntializer();

        questions.result(questionList);


    }


}