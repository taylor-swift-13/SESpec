import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

    //@ requires positions != null && positions.length > 0;
    //@ ensures (\exists int i; 0 <= i && i < positions.length; positions[i] > 0) ==> (\forall int j; 0 <= j && j < positions.length; positions[j] > 0 ==> \result >= positions[j]);
 
    public static int largestPos(int[] positions) {
        int largest = 0;
        //@ maintaining 0 <= count && count <= positions.length;
        //@ maintaining (\forall int i; 0 <= i && i < count; positions[i] > 0 ==> largest >= positions[i]);
 
        //@ decreases positions.length - count;
        for (int count = 0; count < positions.length; count++) {
            if (positions[count] > 0 && positions[count] > largest) {
                largest = positions[count];
            }
        }
        return largest;
    }
}
