import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountNo {

    /*@
      @ requires code != 0;
      @ requires b >= 1;
      @ // ensure termination when the loop executes
      @ requires c < Integer.MAX_VALUE;
      @
      @ // If the b-th integer in [l..c] that is not divisible by code exists, result is its value.
      @ ensures (\result != -1) ==>
      @          (l <= \result && \result <= c
      @           && (\sum int k; l <= k && k <= \result; ((k % code != 0) ? 1 : 0)) == b
      @           && (\forall int u; l <= u && u < \result;
      @                 (\sum int k; l <= k && k <= u; ((k % code != 0) ? 1 : 0)) < b));
      @
      @ // Otherwise, return -1.
      @ ensures (\result == -1) <==>
      @          (\forall int t; l <= t && t <= c;
      @               (\sum int k; l <= k && k <= t; ((k % code != 0) ? 1 : 0)) < b);
      @*/
	public static int countNo(int code, int b, int l, int c) {
		int ret = 0;
        /*@
          @ maintaining l <= loop && loop <= c + 1;
          @ maintaining 0 <= ret && ret <= (loop - l);
          @ maintaining ret == (\sum int k; l <= k && k < loop; ((k % code != 0) ? 1 : 0));
          @ decreases c - loop + 1;
          @*/
		for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
		return -1;
	}
}