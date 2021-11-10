import java.util.ArrayList;
import java.util.Scanner;

public class Questions {

    Scanner in = new Scanner(System.in);

    public Questions(){

    }

    public ArrayList<String> PracticeQuestionsIntializer(){
        ArrayList<String> questions = new ArrayList<>();
        String QuestionAsked1 = "You helped an old man carry heavy luggage bags. You could not let him carry all his bags up the stairs so you helped him. The next day " +
                "he came to find you and offered a gift to thank you for last night's help. \n " +
                "Which gift will you choose? \n" +
                "1. Shiny Crystal Ball \n" +
                "2. Big chunk of gold\n" +
                "3. Pearl emitting light \n" +
                "4. Beautiful Flowers";
        String QuestionAsked2 = "Tomorrow is the day! Romantic date you have been looking forward to." +
                "Your best friend asked you to hear him out because he's going through a lot at the moment.\n" +
                "He insists it needs to be tomorrow. What will you do? \n" +
                "1. Go see your friend \n" +
                "2. Go to the date, meet your friend at night\n" +
                "3. Rearrange the date \n" +
                "4. Apologize to your friend and go to the date \n" +
                "5. Talk to your lover about this";

        System.out.println(QuestionAsked1);
        String Question1 = in.nextLine();
        System.out.println(QuestionAsked2);
        String Question2 = in.nextLine();

        questions.add(Question1);
        questions.add(Question2);

        return questions;

    }

    public void PracticeResult(ArrayList<String> questions){

        System.out.println("For the first question you answered:");
        switch(questions.get(0)){
            case "1":
                System.out.println("You chose Shiny Crystal Ball.\n" +
                        "You are a cool-hearted lover. Often afraid to approach someone unless they approach you first. \n" +
                        "Likely to be afraid to get hurt in a relationship and best fit with someone that gives warmth and expressive.");
                break;
            case "2":
                System.out.println("You chose a big chunk of gold. \n" +
                        "You may seem like a playboy, but deep down are loyal lover.");
                break;
            case "3":
                System.out.println("You chose Pearl emitting light. \n" +
                        "You believe in true love and are satisfied with whats given by your lover.\n");
                break;
            case "4":
                System.out.println("You chose Beautiful flowers. \n" +
                        "You think and look for things that will make who you love be happy. \n" +
                        "If your lover is willing to understand and compromise, you will be in a healthy relationship");
                break;
            default:
                System.out.println("Wrong input.");
                break;
        }

        System.out.println("");
        System.out.println("For the second question you answered:");

        switch(questions.get(1)){
            case "1":
                System.out.println("You chose to go to see your friend \n" +
                        "You are the type to chose friendship over love. Tend to meet your lover with a group of friends. \n" +
                        "Type to build a strong friendship with your lover, but be aware that may not be what your lover wants from their relationship.");
                break;
            case "2":
                System.out.println("You chose going to the date then meeting your friend afterwards. \n" +
                        "Friends and lover are both precious to you. You have trouble prioritizing and lack decisiveness. \n" +
                        "Try stepping up!");
                break;
            case "3":
                System.out.println("You chose Rearranging the date. \n" +
                        "You prioritize relationship with your lover over friends, but do respect your friend's situations too.\n" +
                        "You take your surroundings into consideration.");
                break;
            case "4":
                System.out.println("You chose Apologizing to your friends and go to the date. \n" +
                        "You don't take relationships seriously. Or not good with committed relationship. \n" +
                        "Perhaps having deep conversation with your lover and getting to know your lover might worth a try.");
                break;
            case "5":
                System.out.println("You chose Talking to your lover about the situation. \n" +
                        "You love your friends and your lover." +
                        "You are detailed, passionate person who fall for someone deeply. \n" +
                        "It is very important for you to know passion and interest of your own before the other person. ");
                break;
            default:
                System.out.println("Wrong input.");
                break;
        }

    }


}
