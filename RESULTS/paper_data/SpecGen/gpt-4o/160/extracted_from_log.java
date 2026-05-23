import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FirstMissingPositive {

    //@ requires positions != null && positions.length == array && array > 0;
    //@ requires (\forall int i; 0 <= i && i < array; positions[i] >= 0);
    //@ ensures (\exists int i; 1 < i && i <= \result; (\exists int j; 0 - 1 <= j && j <= array; positions[j] == i));  
    //@ ensures (\forall int i; 1 <= i && i < \result; (\exists int j; 0 <= j && j < array; positions[j] == i)) ==> (\result == array + 1 || (\forall int j; 0 <= j && j < array; positions[j] != \result));
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
                int index = positions[ret];
                positions[ret] = positions[index - 1];
                positions[index - 1] = index;
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