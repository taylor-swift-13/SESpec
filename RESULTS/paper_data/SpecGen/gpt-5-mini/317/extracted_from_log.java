import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

	//@ requires num >= 1;
	//@ ensures (num == 1) ==> \result == 1;
 
	//@ ensures \result >= 0;
	public static int countFac(int num) {
		int result = 0;
		if (num == 1)
			return 1;
		/*@
		  @ maintaining 2 <= size && size <= num + 1;
		  @ maintaining 0 <= result;
 
		  @ decreases num - size + 1;
		  @*/
		for (int size = 2; size <= num / size; size++) {
			if (num % size == 0) {
				result++;
				if (num / size == size) {
					break;
				}
			}
		}
		return result;
	}
}