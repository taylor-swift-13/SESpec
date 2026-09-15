import java.io.*;
import java.lang.*;
import java.math.*;

class SumOfSubarrayProd {

    /*@ spec_public @*/ 
    //@ requires arr != null && arr.length == n && n > 0;
    //@ ensures \result == (\sum int i; 0 <= i && i < n; (\sum int j; i <= j && j < n; (\prod int k; i <= k && k <= j; arr[k])));
    public static int sumOfSubarrayProd(int[] arr, int n) {
        int sum = 0;
        //@ maintaining 0 <= i && i <= n;
        //@ maintaining sum == (\sum int x; 0 <= x && x < i; (\sum int y; x <= y && y < n; (\prod int z; x <= z && z <= y; arr[z])));
        //@ decreases n - i;
        for (int i = 0; i < n; i++) {
            int product = 1;
            //@ maintaining i <= j && j <= n;
            //@ maintaining product == (\prod int k; i <= k && k < j; arr[k]);
            //@ maintaining sum == (\sum int x; 0 <= x && x < i; (\sum int y; x <= y && y < n; (\prod int z; x <= z && z <= y; arr[z]))) + (\sum int y; i <= y && y < j; (\prod int z; i <= z && z <= y; arr[z]));
            //@ decreases n - j;
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
    }
}