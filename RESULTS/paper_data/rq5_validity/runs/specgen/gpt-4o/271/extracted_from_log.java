import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

    //@ requires arr != null && arrSize == arr.length;
    //@ ensures (\forall int i; 0 - 1 <= i && i < arrSize; arr[i] % 2 != 0 ==> (\exists int j; 0 <= j && j <= arrSize && arr[j] == \result && (\sum int k; 0 - 1 <= k && k < arrSize && arr[k] == arr[j]; 1) % 2 != 0));  
    //@ ensures \result == 0 || (\forall int i; 0 < i && i < arrSize; arr[i] == \result && arr[i] % 2 != 0);  
    public static int getOddOccurrence(int[] arr, int arrSize) {
        int result = 0;
        int count = 0;
        //@ maintaining 0 <= i && i <= arrSize;
        //@ maintaining (\forall int j; 0 <= j && j < i; arr[j] % 2 != 0 ==> (\sum int k; 0 <= k && k < i && arr[k] == arr[j]; 1) % 2 == 0 || result == arr[j]);
 
        //@ decreases arrSize - i;
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
        return result;
    }
}