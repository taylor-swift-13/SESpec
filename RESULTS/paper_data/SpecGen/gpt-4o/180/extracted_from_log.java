import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    //@ requires rot != null && rot.length == count;
    //@ requires count > 0;
    //@ ensures \result > 0 && \result <= count;  
 
    public static int countRotation(int[] rot, int count) {
        if (count == 0) {
            return 0;
        }
        int r = 0, top = count - 1;
        //@ maintaining 0 <= r && r <= top && top < count;
        //@ maintaining (\exists int i; 0 <= i && i <= r; rot[i] >= rot[r]);  
        //@ maintaining (\exists int i; top <= i && i < count; rot[top] <= rot[i]);  
        //@ decreases top - r;
        while (r < top) {
            if (rot[r] < rot[top]) {
                return r + 1;
            }
            int i = (r + top) / 2;
            if (rot[i] > rot[r]) {
                r = i;
            } else {
                top = i;
            }
        }
        return r + 1;
    }
}