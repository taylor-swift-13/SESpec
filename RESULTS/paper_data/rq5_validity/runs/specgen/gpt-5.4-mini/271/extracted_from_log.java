import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {
    //@ requires arr != null;
    //@ requires 0 <= arrSize && arrSize <= arr.length;
 
    //@             (\num_of int j; 0 <= j && j < arrSize && arr[j] == arr[i]) % 2 != 0)
    //@         ==> (\exists int i; 0 <= i && i < arrSize; arr[i] == \result);
    //@ ensures (\forall int i; 0 <= i && i < arrSize; arr[i] % 2 == 0) ==> \result == 0;
    public static int getOddOccurrence(int[] arr, int arrSize) {
        int result = 0;
        int count = 0;
        //@ maintaining 0 <= i && i <= arrSize;
        //@ maintaining 0 <= count && count <= i;
        //@ maintaining (count % 2 == 0) ==> (result == 0 || (\exists int k; 0 <= k && k < i; arr[k] == result));
        //@ maintaining (count % 2 != 0) ==> (\exists int k; 0 <= k && k < i; arr[k] == result && arr[k] % 2 != 0);
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