import java.util.Scanner;

public class Calculator {

    public static void main (String[] args){

        Scanner in = new Scanner(System.in);

        System.out.println("Please leave a space after a number or signs. Available signs are +, -, *, %, / \n" +
                "Ex. 4 + 5 or 4 * 20 \n" +
                "Enter -1234567 to end the program. \n");

        double validator = 0;
        calculate calc = new calculate();
        String input = "";

        while(validator != -1234567){

            System.out.println("Enter numbers and signs: ");
            input = in.nextLine();
            validator = calc.calculatorAlgorithm(input);

            System.out.println("Answer is " + validator);

        }

    }

}
