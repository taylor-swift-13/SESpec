import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    //@ assignable \nothing;
    //@ ensures 0 <= \result;
    //@ ensures \result == (\sum int i; 1 <= i && i <= ((\old(z) < 0) ? -\old(z) : \old(z)) && num % i == 0; 1);
	public static int findDivisor(int num, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
        //@ maintaining 1 <= loop;
        //@ maintaining 0 <= result;
        //@ maintaining result == (\sum int i; 1 <= i && i < loop && i <= z && num % i == 0; 1);
		for (int loop = 1; loop <= z; loop++) {
			if (num % loop == 0) {
				result = result + 1;
			}
		}
		return result;
	}
}