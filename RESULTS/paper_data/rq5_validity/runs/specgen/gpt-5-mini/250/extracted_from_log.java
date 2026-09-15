import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= start && start <= stop && stop < args.length;
	  @ ensures  start <= \result && \result <= stop + 1;
 
	  @ ensures (\forall int i; \result <= i && i <= stop; args[i] >= i);  
	  @*/
	public static int findFirstMissing(int[] args, int start, int stop) {
		int result = start;
		int total = stop;
		int mid;

		/*@ 
		  @ maintaining start <= result && result <= total + 1 && total >= start - 1 && total <= stop;
 
 
		  @ maintaining result <= total + 1;
 
		  @ decreases total - result + 1;
		  @*/
		while (result <= total) {
			mid = (result + total) / 2;
			int i = args[mid];

			if (i == mid) {
				result = mid + 1;
			} else if (i < mid) {
				result = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return result;
	}
}