import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRotation {

    //@ requires rot != null;
    //@ requires 0 <= count && count <= rot.length;
    //@ ensures count == 0 ==> \result == 0;
    //@ ensures count > 0 ==> 1 <= \result && \result <= count;
    //@ ensures (\forall int k; 0 <= k && k < rot.length; rot[k] == \old(rot[k]));
	public static int countRotation(int[] rot, int count) {
		if (count == 0) {
			return 0;
		}
		int r = 0, top = count - 1;
        //@ maintaining 0 <= r && r <= top && top < count;
        //@ maintaining (\forall int k; 0 <= k && k < rot.length; rot[k] == \old(rot[k]));
        //@ decreases top - r;
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