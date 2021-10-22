import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class BalanceGame {

    public static void main(String[] args) throws FileNotFoundException {

        ArrayList<String> array = new ArrayList<>();
        ArrayList<String> entireList = new ArrayList<>();

        Scanner in = new Scanner(System.in);

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

            csvReader(entireList, "tempcsv.csv");
            arrayAdder(entireList, array, numberOfRounds);
        }else{
            System.out.println("Invalid entry for number of rounds");
        }

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
    public static void csvReader(ArrayList<String> entireList, String filename) throws FileNotFoundException {

        Scanner sc = new Scanner(new File(filename));

        sc.useDelimiter("\n");

        int i = 0;
        while(sc.hasNext()){
            entireList.add(i,sc.next());
            i++;
        }

    }

}
