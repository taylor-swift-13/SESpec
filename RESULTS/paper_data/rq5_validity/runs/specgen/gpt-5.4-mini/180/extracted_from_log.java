import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

	/*@ requires rot != null;
	  @ requires 0 <= count && count <= rot.length;
	  @ ensures (\result == 0) <==> (count == 0);
	  @ ensures count > 0 ==> 0 < \result && \result - 1 <= count;  
	  @*/
	public static int countRotation(int[] rot, int count) {
		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		/*@ maintaining 0 <= r && r <= top + 1 && top < count;
		  @ maintaining 0 <= top && top < count;
		  @ decreases top - r;
		  @*/
		while (r < top) {
			if (rot[r] < rot[top]) {
				return r + 1;
			}
			int i = (r + top) / 2;
			if (rot[i] > rot[r]) {
				r = i;
			} else {
				top = i;
			}
		}
		return r + 1;
	}
}