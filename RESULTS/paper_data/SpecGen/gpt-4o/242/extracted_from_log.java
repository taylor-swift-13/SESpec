import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

    //@ requires nums != null && nums.length > 0;
    //@ ensures (\exists int i; 0 < i && i < nums.length; nums[i] >= \result ==> (\exists int j; 0 < j && j <= nums.length; nums[j] == nums[i] - \result));  
    //@ ensures (\forall int i; 0 <= i && i < nums.length; nums[i] <= \result ==> (\exists int j; 0 <= j && j < nums.length; nums[j] == nums[i] + \result));
    //@ ensures \result == (\max int i; 0 <= i && i < nums.length; nums[i]) - (\min int i; 0 <= i && i < nums.length; nums[i]);
    public static int bigDiff(int[] nums) {
        int max = nums[0];
        int min = nums[0];
        //@ maintaining 1 <= i && i <= nums.length;
        //@ maintaining (\forall int j; 0 <= j && j < i; nums[j] <= max);
        //@ maintaining (\forall int j; 0 <= j && j < i; nums[j] >= min);
        //@ decreases nums.length - i;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        return max - min;
    }
}