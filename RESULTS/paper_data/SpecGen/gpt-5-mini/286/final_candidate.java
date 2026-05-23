import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class JacobsthalNum {

	/*@ requires j >= 1 && j <= 30;
	  @ ensures \result == ((1 << j) - ( (j % 2 == 0) ? 1 : -1 )) / 3;
	  @*/
	public static int jacobsthalNum(int j) {
		int r[] = new int[j + 1];
		r[0] = 0;
		r[1] = 1;
		/*@ maintaining r.length == j + 1;
		  @ maintaining r[0] == 0 && r[1] == 1;
		  @ maintaining (\forall int q; 2 <= q && q < p; r[q] == r[q-1] + 2*r[q-2]);
		  @ decreases j - p + 1;
		  @*/
		for (int p = 2; p <= j; p++) {
			r[p] = r[p - 1]
					+ 2 * r[p - 2];
		}
		return r[j];
	}
}