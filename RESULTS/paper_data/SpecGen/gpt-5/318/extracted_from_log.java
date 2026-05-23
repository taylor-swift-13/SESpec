import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountFac {

    //@ ensures (num == 1) ==> (\result == 1);
    //@ ensures (num != 1) ==> (\result == (\sum int c; 2 <= c && c*c <= num && num % c == 0; 1));
    //@ ensures \result >= 0;
	public static int countFac(int num) {
		int result = 0;
		if (num == 1)
			return 1;
        //@ maintaining c >= 2;
        //@ maintaining 0 <= result;
        //@ maintaining result == (\sum int d; 2 <= d && d < c && d*d <= num && num % d == 0; 1);
        //@ decreases num - c*c;
		for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
		return result;
	}
}