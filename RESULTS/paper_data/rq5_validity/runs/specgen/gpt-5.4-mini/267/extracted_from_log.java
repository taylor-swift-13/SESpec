import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

	//@ requires args != null;
	//@ requires 0 <= array && array <= args.length;
 
 
	public static int getOddOccurrence(int[] args, int array) {
		int ret = 0;
		int start = 0;
		//@ maintaining 0 <= index && index <= array;
		//@ maintaining 0 <= start && start <= index;
		//@ maintaining (\forall int i; 0 <= i && i < index; args[i] % 2 == 0 || args[i] % 2 != 0);
		//@ decreases array - index;
		for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
		return ret;
	}
}