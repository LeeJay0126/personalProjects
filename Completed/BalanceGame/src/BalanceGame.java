import java.io.*;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class BalanceGame {

    public static void main(String[] args) throws IOException {

        ArrayList<String> array = new ArrayList<>();
        ArrayList<String> entireList = new ArrayList<>();

        Scanner in = new Scanner(System.in);

        System.out.println("Which balance game would you like to play? \n" +
                "Enter 1 for League of Legends Favourite Champion \n" +
                "Enter 2 for Favourite NBA player ");

        int gameCode = Integer.parseInt(in.nextLine());
        String filename = "";

        if(gameCode == 1){
            filename = "champions.csv";
        }else if(gameCode == 2){
            filename = "NBA.csv";
        }else{
            System.out.println("Please Enter a valid number! \n" +
                    "League of Legends Champion balance game has been chosen automatically");
            filename = "champions.csv";
            gameCode = 1;
        }

        System.out.println("How many rounds would you like to play in? \n" +
                "Enter 1 for rounds of 16 \n" +
                "Enter 2 for rounds of 32 \n" +
                "Enter 3 for rounds of 64");

        int rounds = Integer.parseInt(in.nextLine());
        int numberOfRounds = 0;

        switch(rounds){
            case 1:
                numberOfRounds = 16;
                break;
            case 2:
                numberOfRounds = 32;
                break;
            case 3:
                numberOfRounds = 64;
                break;
            default:
                break;
        }

        if(numberOfRounds != 0) {
            csvReader(entireList, filename);
            arrayAdder(entireList, array, numberOfRounds);

        }else{
            System.out.println("Invalid entry for number of rounds");
        }


        ArrayList<String> resultArray = new ArrayList<>();

        resultArray = gamePlayer(array, gameCode);

        for(int i = 0; i < resultArray.size(); i++){
            System.out.println("Your pick is: " + resultArray.get(i));
        }



    }

    //recursive method until size of arraylist is 1
    public static ArrayList<String> gamePlayer(ArrayList<String> array, int gameCode){

        Scanner in = new Scanner(System.in);

        if(array.size() == 1){
            return array;
        }

        String Question;

        if(gameCode == 1){
            Question = "Which League of Legends Champion do you like more? \n";
        }else{
            Question = "Which NBA player do you like more? \n";
        }


        if(array.size() == 2){
            System.out.println("Finals");
        }else if(array.size() == 4){
            System.out.println("SemiFinals");
        }else {
            System.out.println("Round of " + array.size());
        }

        ArrayList<String> newArray = new ArrayList<>();
        String first;
        String second;
        int choice;

        for( int i = 0; i < array.size(); i += 2){
            first = array.get(i);
            second = array.get(i+1);

            System.out.println(Question +
                    "Enter 1 for " + first + "\n" +
                    "Enter 2 for " + second);
            choice = Integer.parseInt(in.nextLine());

            if(choice == 1){
                newArray.add(array.get(i));
            }else{
                newArray.add(array.get(i+1));
            }
        }

        return gamePlayer(newArray, gameCode);

    }

    //Method that can be used for different number of rounds
    public static ArrayList<String> arrayAdder(ArrayList<String> entireList, ArrayList<String> resultArray, int numberOfRounds){

        int randomNumber;
        Random rand = new Random();
        int upperbound = entireList.size() -1;

        int i = 0;
        while (i < numberOfRounds){
            randomNumber = rand.nextInt(upperbound-1);
            if(!(resultArray.contains(entireList.get(randomNumber)))){
                resultArray.add(i,entireList.get(randomNumber));
                i++;
            }
        }

        return resultArray;

    }

    //
    public static void csvReader(ArrayList<String> entireList, String filename) throws IOException {

        File file = new File(filename);
        FileInputStream ft = new FileInputStream(file);

        DataInputStream in = new DataInputStream(ft);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        String line;

        int i = 0;
        while((line = br.readLine()) != null){
            entireList.add(i,line);
            i++;
        }

    }

}
