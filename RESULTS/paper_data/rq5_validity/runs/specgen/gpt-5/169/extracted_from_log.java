import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

/*@ spec_public @*/
class FindRotationCount {

	/*@ 
	  @ requires arr != null;
	  @ assignable \nothing;
	  @ ensures arr.length == 0 ==> \result == 0;
	  @ ensures arr.length > 0 ==> (0 <= \result && \result < arr.length);
	  @*/
	/*@ spec_public @*/ public static int findRotationCount(int[] arr) {
		int r = 0;
		int stop = arr.length - 1;
		//@ maintaining 0 <= r && r <= arr.length;
		//@ maintaining -1 <= stop && stop < arr.length;
		//@ maintaining r <= stop + 1;
		//@ maintaining 0 <= stop - r + 1;
		//@ decreases stop - r + 1;
		while (r <= stop) {
			int i = r + (stop - r) / 2;
			if (i < stop
					&& arr[i] > arr[i + 1]) {
				return i + 1;
			} else if (i > r
					&& arr[i] < arr[i - 1]) {
				return i;
			}
			if (arr[i] >= arr[r]) {
				r = i + 1;
			} else {
				stop = i - 1;
			}
		}
		return 0;
	}
}