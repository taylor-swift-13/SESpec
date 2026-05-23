import java.io.*;
import java.lang.*;
import java.math.*;

class UniqueElement {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ ensures (\result.equals("NO") <==> (n == 0 || (\exists int i; 1 <= i && i < n; arr[i] != arr[0])));
    //@ ensures (\result.equals("YES") <==> (n > 0 && (\forall int i; 1 <= i && i < n; arr[i] == arr[0])));
    //@ ensures \result.equals("YES") || \result.equals("NO");
    public static String uniqueElement(int[] arr, int n) {
        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        //@ maintaining 1 <= i && i <= n;
        //@ maintaining (\forall int k; 1 <= k && k < i; arr[k] == firstElement);
        //@ decreases n - i;
        for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
    }
}