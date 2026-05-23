import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

	/*@ public normal_behavior
	  @   requires true;
	  @   assignable \nothing;
	  @   ensures 0 <= \result;
	  @   ensures \result <= (\old(z) < 0 ? -\old(z) : \old(z));
	  @*/
	public /*@ spec_public @*/ static int findDivisor(int num, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
		/*@ maintaining 1 <= index && index <= z + 1;
		  @ maintaining 0 <= result && result <= index - 1;
		  @ decreases z - index + 1;
		  @*/
		for (int index = 1; index <= z; index++) {
			if (num % index == 0) {
				result = result + 1;
			}
		}
		return result;
	}
}