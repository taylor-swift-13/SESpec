import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class LastTwoDigits {

	/*@ 
	  @ requires num >= 0;
	  @ ensures 0 <= \result && \result < 100;
 
 
	  @ ensures (\exists long f; f == (\product int i; 1 < i && i < num; i) || \result == (int)(f % 100));  
	  @*/
	public static int lastTwoDigits(int num) {
		int ret = 1;
		//@ maintaining 1 <= number && number <= num + 1;
 
		//@ decreases num - number + 1;
		for (int number = 1; number <= num; number++) {
			ret *= number;
		}
		int result = (int) (ret % 100);
		return result;
	}
}
