import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

    //@ requires positions != null && positions.length > 0;
    //@ ensures \result == (\max int i; 0 < i && i < positions.length && positions[i] >= 0; positions[i]) && (\exists int i; 0 < i && i <= positions.length; positions[i] < 0) ==> \result == 0;  
    public static int largestPos(int[] positions) {
        int largest = 0;
        //@ maintaining 0 <= index && index <= positions.length;
        //@ maintaining (\forall int i; 0 <= i && i < index; positions[i] > 0 ==> positions[i] <= largest);
        //@ maintaining (\forall int i; 0 <= i && i < index; positions[i] <= 0 ==> largest >= 0);
        //@ decreases positions.length - index;
        for (int index = 0; index < positions.length; index++) {
            if (positions[index] > 0 && positions[index] > largest) {
                largest = positions[index];
            }
        }
        return largest;
    }
}
