import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {

	/*@ 
	  requires args != null;
	  requires 0 <= start && start <= stop && stop < args.length;
	  // require monotonic non-decreasing array on the search interval to make the problem well-formed
	  requires (\forall int i, j; start <= i && i < j && j <= stop; args[i] <= args[j]);
	  
	  // result is an index in [start, stop+1]
	  ensures start <= \result && \result <= stop + 1;
	  // all indices before result satisfy args[k] <= k
	  ensures (\forall int k; start <= k && k < \result; args[k] <= k);
	  // all indices from result to stop satisfy args[k] > k
	  ensures (\forall int k; \result <= k && k <= stop; args[k] > k);
	@*/
	public static int findFirstMissing(int[] args, int start, int stop) {
		int found = start;
		int num = stop;
		int mid;

		/*@ 
		  // loop invariant: bounds on found and num
		  maintaining start <= found && found <= num + 1 && num <= stop;
		  // all indices < found satisfy args[idx] <= idx
		  maintaining (\forall int idx; start <= idx && idx < found; args[idx] <= idx);
		  // all indices > num satisfy args[idx] > idx
		  maintaining (\forall int idx; num < idx && idx <= stop; args[idx] > idx);
		  // variant ensures termination
		  decreases num - found + 1;
		@*/
		while (found <= num) {
			mid = (found + num) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				num = mid - 1;
			}
		}
		return found;
	}
}