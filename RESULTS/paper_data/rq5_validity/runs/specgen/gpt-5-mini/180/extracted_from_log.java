import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

	/*@ 
	  @ requires rot != null;
	  @ requires count >= 0 && count <= rot.length;
	  @ ensures count == 0 ==> \result == 0;
	  @ ensures count > 0 ==> 1 <= \result && \result <= count;
	  @ ensures 0 <= \result && \result <= count;
	  @*/
	public static int countRotation(int[] rot, int count) {
		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
		/*@ 
		  @ maintaining 0 <= r && r < count;
		  @ maintaining 0 <= top && top < count;
		  @ maintaining r <= top;
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