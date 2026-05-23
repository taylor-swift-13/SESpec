import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class FindFirstMissing {
	/*@ public normal_behavior
	  @   requires args != null;
	  @   requires 0 <= start && start <= stop && stop < args.length;
	  @   // monotonicity: once args[i] > i holds at some index i, it holds for all larger indices in the range
	  @   requires (\forall int i, j; start <= i && i <= j && j <= stop; (args[i] > i) ==> (args[j] > j));
	  @   ensures start <= \result && \result <= stop + 1;
	  @   ensures (\forall int i; start <= i && i < \result; args[i] <= i);
	  @   ensures (\forall int i; \result <= i && i <= stop; args[i] > i);
	  @*/
	public static int findFirstMissing(int[] args, int start, int stop) {
		int found = start;
		int total = stop;
		int mid;

		/*@ maintaining 0 <= start && start <= found && found <= total + 1 && total <= stop;
		  @ maintaining (\forall int i; start <= i && i < found; args[i] <= i);
		  @ maintaining (\forall int i; total + 1 <= i && i <= stop; args[i] > i);
		  @ decreases total - found + 1;
		  @*/
		while (found <= total) {
			mid = (found + total) / 2;
			int i = args[mid];

			if (i == mid) {
				found = mid + 1;
			} else if (i < mid) {
				found = mid + 1;
			} else {
				total = mid - 1;
			}
		}
		return found;
	}
}