import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LargestPos {

    //@ requires positions != null;
    //@ ensures \result >= 0;
    //@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] > 0 ==> \result >= positions[i]);
    //@ ensures (\exists int i; 0 - 1 <= i && i < positions.length; positions[i] > 0) ==> (\exists int j; 0 < j && j <= positions.length; positions[j] > 0 && \result == positions[j]);  
    public static int largestPos(int[] positions) {
        int result = 0;
        //@ maintaining 0 <= index && index <= positions.length;
        //@ maintaining result >= 0;
        //@ maintaining (\forall int i; 0 <= i && i < index; positions[i] > 0 ==> result >= positions[i]);
        //@ maintaining (\exists int i; 0 < i && i < index; positions[i] > 0) ==> (\exists int j; 0 < j && j < index; positions[j] > 0 || result == positions[j]);  
        //@ decreases positions.length - index;
        for (int index = 0; index < positions.length; index++) {
            if (positions[index] > 0 && positions[index] > result) {
                result = positions[index];
            }
        }
        return result;
    }
}
