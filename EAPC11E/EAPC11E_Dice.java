import java.util.*;
import java.io.*;

public class EAPC11E {
    static Scanner sc = new Scanner(System.in);

    public void run() {
        int[] die = {1,2,6,5,3,4};

        int posX = 0;
        int posY = 0;
        boolean isReversed = false;

        char[] input = sc.next().toCharArray();

        int currentNumber = 0;

        for (int i = 0; i < input.length; i++) {
            switch (input[i]){
                case '+' :
                    isReversed = false;
                    break;
                case '-' :
                    isReversed = true;
                    break;
                case '.' :
                    System.out.println("position ("+posX+","+posY+"), "+die[0]+" dots");
                    return;
                case 'Y' :
                    if(currentNumber == 0) currentNumber = 1;
                    if(isReversed){
                        posY -= currentNumber;
                        die = newDie(die, (-1)*currentNumber, true);
                    } else {
                        posY += currentNumber;
                        die = newDie(die, currentNumber, true);
                    }
                    currentNumber = 0;
                    break;
                case 'X' :
                    if(currentNumber == 0) currentNumber = 1;
                    if(isReversed){
                        posX -= currentNumber;
                        die = newDie(die, (-1)*currentNumber, false);
                    } else {
                        posX += currentNumber;
                        die = newDie(die, currentNumber, false);
                    }
                    currentNumber = 0;
                    break;
                default:
                    currentNumber = currentNumber * 10 + Character.getNumericValue(input[i]);
                    break;
            }
        }
    }

    public int[] newDie(int[] die, int currentNumber, boolean NS) {
        int[] oldDie = die;
        int[] newDie = die;
        int moves = (currentNumber % 4 + 4) % 4;
        /*
        !!!
        % gives remainder, not mod
        http://stackoverflow.com/questions/4412179/best-way-to-make-javas-modulus-behave-like-it-should-with-negative-numbers/4412200#4412200
        !!!
         */
        while(moves-- > 0) {
            if (NS) {
                int[] helperDie = {oldDie[1],oldDie[2],oldDie[3],oldDie[0],oldDie[4],oldDie[5]};
                newDie = helperDie;
            } else {
                int[] helperDie = {oldDie[4],oldDie[1],oldDie[5],oldDie[3],oldDie[2],oldDie[0]};
                newDie = helperDie;
            }
            oldDie = newDie;
        }
        return newDie;
    }


    public static void main(String args[]) {
        int runs = sc.nextInt();
        for (int i = 0; i < runs; i++) {
            new EAPC11E().run();
        }
    }
}