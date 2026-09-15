import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class EvenPowerSum {

    /*@ 
      @ requires p >= 0;
 
      @*/
	public static int evenPowerSum(int p) {
		int odd = 0;
		//@ maintaining 1 <= c && c <= p + 1;
 
		//@ decreases p - c + 1;
		for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
		return odd;
	}
}
