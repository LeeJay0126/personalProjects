import java.util.ArrayList;

public class calculate {

    calculate(){

    }

    public double calculatorAlgorithm(String input){

        String[] parts = input.split(" ");
        ArrayList <Double> numbers = new ArrayList<>();
        ArrayList <String> signs = new ArrayList<>();

        for(int i = 0; i < parts.length; i++){

            if(i%2 == 0){
                numbers.add(Double.parseDouble(parts[i]));
            }else{
                signs.add(parts[i]);
            }
        }

        int counter = 0;
        double result = 0;

        for(int i = 0; i <= numbers.size(); i ++){

            if(i == 0){

                result = numbers.get(i);

            }else {

                if (signs.get(counter) == "*") {
                    result *= numbers.get(i);
                } else if (signs.get(counter) == "+") {
                    result += numbers.get(i);
                } else if (signs.get(counter) == "-") {
                    result -= numbers.get(i);
                } else if (signs.get(counter) == "/") {
                    result /= numbers.get(i);
                } else if (signs.get(counter) == "%") {
                    result /= numbers.get(i);
                } else {
                    return -123456789;
                }

            }

            counter++;

        }

        return result;

    }

}
