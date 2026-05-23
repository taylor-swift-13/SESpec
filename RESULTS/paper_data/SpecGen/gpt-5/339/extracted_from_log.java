import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindDivisor {

    /*@
      @ ensures z == ((\old(z) < 0) ? -\old(z) : \old(z));
      @ ensures 0 <= \result && \result <= z;
      @ ensures z == 0 ==> \result == 0;
      @ ensures num == 0 ==> \result == z;
      @*/
	public /*@ spec_public @*/ static int findDivisor(int num, int z) {
		if (z < 0) {
			z = -z;
		}
		int result = 0;
        /*@
          @ maintaining 1 <= index && index <= z + 1;
          @ maintaining z >= 0;
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