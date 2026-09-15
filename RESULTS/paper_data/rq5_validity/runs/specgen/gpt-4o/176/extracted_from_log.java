import java.io.*;
import java.lang.*;
import java.util.*;

class FindLastOccurrence {

    //@ requires arr.length > 0;
    //@ requires \forall int j; 0 <= j && j < arr.length; \forall int i; 0 <= i && i < j; arr[i] <= arr[j];
 
    //@ ensures 0 <= \result && \result < arr.length ==> arr[\result] == array && (\result == arr.length - 1 || arr[\result + 1] != array);
    public static int findLastOccurrence(int[] arr, int array) {
        int found = 0;
        int hi = arr.length - 1;
        int end = 0;
        //@ maintaining 0 <= found && found <= hi + 1 && hi < arr.length;
        //@ maintaining (\forall int i; 0 < i && i < found; arr[i] <= array);  
        //@ maintaining (\forall int i; hi + 1 <= i && i < arr.length; arr[i] > array);
        //@ decreases hi - found + 1;
        while (found <= hi) {
            end = (found + hi) / 2;
            if (arr[end] == array) {
                if (end == arr.length - 1
                        || arr[end + 1] != array) {
                    return end;
                } else {
                    found = end + 1;
                }
            } else if (arr[end] < array) {
                found = end + 1;
            } else {
                hi = end - 1;
            }
        }
        return -1;
    }
}