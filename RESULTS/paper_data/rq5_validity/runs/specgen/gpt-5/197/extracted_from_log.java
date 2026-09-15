import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CatalanNumber {

    /*@ public model pure static \bigint Cat(int m);
      @ axiom Cat(0) == 1;
      @ axiom (\forall int m; m > 0 ==> Cat(m) ==
      @            (\sum int i; 0 <= i && i < m; Cat(i) * Cat(m - 1 - i)));
      @*/

    //@ requires 0 <= n && n <= 19;
    //@ ensures \result == (int)Cat(n);
	public static int catalanNumber(int n) {
		int[] arr = new int[n + 1];
		arr[0] = 1;
        //@ maintaining arr.length == n + 1;
        //@ maintaining 1 <= c && c <= n;
        //@ maintaining (\forall int t; 0 <= t && t < c; arr[t] == (int)Cat(t));
        //@ decreases n - c + 1;
		for (int c = 1; c <= n; c++) {
			arr[c] = 0;
            //@ maintaining arr.length == n + 1;
            //@ maintaining 0 <= k && k <= c;
            //@ maintaining 1 <= c && c <= n;
            //@ maintaining (\forall int t; 0 <= t && t < c; arr[t] == (int)Cat(t));
            //@ maintaining arr[c] == (\sum int i; 0 <= i && i < k; arr[i] * arr[c - 1 - i]);
            //@ decreases c - k;
			for (int k = 0; k < c; k++) {
				arr[c] += arr[k]
						* arr[c - k - 1];
			}
		}
		return arr[n];
	}
}