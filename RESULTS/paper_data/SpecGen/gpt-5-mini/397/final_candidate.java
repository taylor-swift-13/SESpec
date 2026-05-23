import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenPowerSum {

	/*@ 
 
 
	  @*/
	public static /*@ spec_public @*/ int evenPowerSum(int p) {
		int even = 0;
		//@ maintaining c >= 1;
		//@ maintaining (p < 1) ==> (/*@*/ true /* loop not entered when p<1, c remains 1 */);
		//@ maintaining (p >= 1) ==> (c <= p + 1);
 
		//@ decreases p - c + 1;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
		return even;
	}
}
