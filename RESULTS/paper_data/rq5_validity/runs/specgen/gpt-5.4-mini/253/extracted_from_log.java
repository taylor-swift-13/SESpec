import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetInvCount {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
 
 
 
    public static int getInvCount(int[] arr, int n) {
        int invCount = 0;

        //@ maintaining 0 <= i && i <= n;
 
        //@ decreasing n - i;
        for (int i = 0; i < n; i++) {
            //@ maintaining i + 1 <= j && j <= n;
            //@ decreasing n - j;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        return invCount;
    }
}