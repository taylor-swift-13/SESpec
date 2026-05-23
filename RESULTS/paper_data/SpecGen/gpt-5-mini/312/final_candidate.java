import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	/*@
	  @ requires count >= 0;
	  @ ensures \result == (\sum int ii; 1 <= ii && ii <= 2*count;
	  @                        (\sum int cc; 1 <= cc && cc <= 2*count && (ii*ii + cc*cc) <= (2*count)*(2*count); 1));
	  @ ensures 0 <= \result && \result <= (2*count)*(2*count);
	  @*/
	public static int countRectangles(int count) {
		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		  @ // invariant: i ranges from 1..diameter+1 during loop and ret counts all pairs (ii,cc) for ii < i
 
 
		  @                        (\sum int cc; 1 <= cc && cc <= diameter && (ii*ii + cc*cc) <= center; 1));
		  @ decreases diameter - (i - 1);
		  @*/
		for (int i = 1; i <= 2 * count; i++) {
			/*@
			  @ // invariant: c ranges from 1..diameter+1 during inner loop and ret counts pairs for ii < i plus cc < c for current i
			  @ maintaining 1 <= c && c <= diameter + 1;
			  @ maintaining ret == (\sum int ii; 1 <= ii && ii < i && ii <= diameter;
			  @                         (\sum int cc; 1 <= cc && cc <= diameter && (ii*ii + cc*cc) <= center; 1))
			  @                    + (\sum int cc; 1 <= cc && cc < c && cc <= diameter && (i*i + cc*cc) <= center; 1);
			  @ decreases diameter - (c - 1);
			  @*/
			for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
		}
		return ret;
	}
}
