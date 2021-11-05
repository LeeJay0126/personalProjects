import java.util.ArrayList;

public class Questions {

    public Questions(){

    }

    public ArrayList<String> questionsIntializer(){
        ArrayList<String> questions = new ArrayList<>();
        String Question1 = "You helped an old man carry heavy luggage bags. You could not let him carry all his bags up the stairs so you helped him. The next day " +
                "he came to find you and offered a gift to thank you for last night's help. Which gift will you choose? \n" +
                "1. Shiny Crystal Ball \n" +
                "2. Big chunk of gold\n" +
                "3. Pearl emitting light \n" +
                "4. Beautiful Flowers";
        String Question2 = "Tomorrow is the day! Romantic date you have been looking forward to." +
                "Your best friend asked you to hear him out because he's going through a lot at the moment." +
                "He insists it needs to be tomorrow. What will you do? \n" +
                "1. Go see your friend \n" +
                "2. Go to the date, meet your friend at night\n" +
                "3. Rearrange the date \n" +
                "4. Apologize to your friend and go to the date" +
                "5. Talk to your lover about this";

        questions.add(Question1);
        questions.add(Question2);

        return questions;

    }

}
