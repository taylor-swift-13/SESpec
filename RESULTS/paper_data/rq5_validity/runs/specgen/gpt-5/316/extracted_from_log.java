import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    /*@
      @ ensures (number == 1) ==> (\result == 1);
      @ ensures (number != 1) ==> (\result == (\num_of int c; 2 <= c && c*c <= number; number % c == 0));
      @ ensures \result >= 0;
      @*/
	public static int countFac(int number) {
		int result = 0;
		if (number == 1)
			return 1;
        //@ maintaining result == (\num_of int d; 2 <= d && d < c; number % d == 0);
        //@ maintaining 2 <= c;
        //@ decreases (number >= 2 ? number - c : 0);
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
	}
}