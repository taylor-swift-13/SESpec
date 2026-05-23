import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

	//@ requires num >= 1;
	//@ ensures (num == 1) ==> (\result == 1);
	//@ ensures (num > 1) ==> (\result >= 0);
	//@ ensures (\forall int d; 1 < d && d < num / d && num % d == 0; \result + 1 >= 1);  
	public static int countFac(int num) {
		int result = 0;
		if (num == 1)
			return 1;
		//@ maintaining 2 <= size && size <= num / size + 1;
		//@ maintaining result >= 0;
		//@ maintaining (\forall int d; 2 <= d && d < size && num % d == 0; result >= 1);
		//@ decreases (num / size) - size + 1;
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