import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindLucas {

    //@ requires num >= 1;
 
    //@ ensures num == 1 ==> \result == 1;
 
	public static int findLucas(int num) {
		int[] result = new int[num + 1];
		result[0] = 2;
		result[1] = 1;
		/*@
		  @ maintaining result.length == num + 1;
		  @ maintaining result[0] == 2 && result[1] == 1;
		  @ maintaining 2 <= l && l <= num + 1;
		  @ decreases num - l + 1;
		  @*/
		for (int l = 2; l <= num; l++) {
			result[l] = result[l - 1]
					+ result[l - 2];
		}
		return result[num];
	}
}