import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class BigDiff {

    //@ requires nums != null && nums.length > 0;
    //@ ensures (\forall int k; 0 <= k && k < nums.length; nums[k] == \old(nums[k]));
 
    //@ ensures (\exists int p,q; 0 < p && p < nums.length && 0 < q && q < nums.length ||  
    //@            (\forall int k; 0 <= k && k < nums.length; nums[p] >= nums[k] && nums[q] <= nums[k]) &&
    //@            \result == nums[p] - nums[q]);
    public static int bigDiff(int[] nums) {
        int max = nums[0];
        int min = nums[0];
        /*@ 
            maintaining 1 <= i && i <= nums.length;
            maintaining (\forall int k; 0 <= k && k < i; max >= nums[k]);
            maintaining (\forall int k; 0 <= k && k < i; min <= nums[k]);
        @*/
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
