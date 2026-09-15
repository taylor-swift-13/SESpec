import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

    //@ requires arr != null && 0 <= arrSize && arrSize <= arr.length;
    //@ ensures (\forall int i; 0 <= i && i < arrSize; arr[i] % 2 == 0) ==> \result == 0;
    //@ ensures \result == 0 || (\exists int i; 0 <= i && i < arrSize; arr[i] % 2 != 0 && \result == arr[i]);
    public static int getOddOccurrence(int[] arr, int arrSize) {
        int result = 0;
        int count = 0;
        //@ maintaining 0 <= i && i <= arrSize;
        //@ maintaining 0 <= count && count <= i;
        //@ maintaining count == (\sum int j; 0 <= j && j < i; (arr[j] % 2 != 0 ? 1 : 0));
        //@ maintaining (count == 0 ==> result == 0);
        //@ maintaining (count > 0 ==> (\exists int k; 0 <= k && k < i; arr[k] % 2 != 0 && result == arr[k]));
        //@ maintaining result == 0 || result % 2 != 0;
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