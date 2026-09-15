import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    //@ requires positions != null && array >= 0 && positions.length == array;
    //@ ensures (\exists int i; 0 < i && i <= \result - 1; \exists int j; 0 - 1 <= j && j <= positions.length; positions[j] == i + 1);  
    //@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] > 0 ==> positions[i] <= positions.length);
    //@ ensures (\forall int i; 0 <= i && i < positions.length; positions[i] == i + 1 ==> positions[i] == i + 1);
    public static int firstMissingPositive(int[] positions, int array) {
        int ret = 0;
        //@ maintaining 0 <= ret && ret <= array;
        //@ maintaining (\forall int i; 0 <= i && i < ret; positions[i] <= 0 || positions[i] > array || positions[i] == i + 1);
        //@ decreases array - ret;
        while (ret < array) {
            if (positions[ret] <= 0 || positions[ret] > array
                    || positions[ret] == ret + 1) {
                ret++;
            } else {
                int j = positions[ret];
                //@ assert 1 <= j && j <= array;
                positions[ret] = positions[j - 1];
                positions[j - 1] = j;
            }
        }
        //@ maintaining 0 <= ret && ret <= array;
        //@ maintaining (\forall int i; 0 <= i && i < ret; positions[i] == i + 1);
        //@ decreases array - ret;
        for (ret = 0; ret < array; ret++) {
            if (positions[ret] != ret + 1) {
                return ret + 1;
            }
        }
        return array + 1;
    }
}