import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

	/*@ 
	  @ requires num >= 0;
	  @ ensures num == 1 ==> \result == 1;
	  @ ensures num != 1 ==> \result == (\num_of int s; 2 <= s && s <= num / s; num % s == 0);
	  @ ensures \result >= 0;
	  @*/
	public static int countFac(int num) {
		int result = 0;
		if (num == 1)
			return 1;
		/*@ 
		  @ maintaining num >= 0;
		  @ maintaining result >= 0;
		  @ maintaining (\exists int m; (m == size - 1 || m == size) &&
		  @                     result == (\num_of int t; 2 <= t && t <= m; num % t == 0));
		  @ decreases num - size;
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