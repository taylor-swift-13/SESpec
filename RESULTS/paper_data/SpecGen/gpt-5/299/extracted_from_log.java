import java.io.*;
import java.lang.*;
import java.math.*;

class FindPeak {

    /*@
      @ requires data != null;
      @ requires 1 <= array && array <= data.length;
      @ assignable \nothing;
      @ ensures 0 <= \result && \result < array;
      @*/
	public static int findPeak(int[] data, int array) {
		int i = 0, top = array - 1;
        /*@
          @ maintaining 0 <= i && i <= top && top < array;
          @ maintaining top - i >= 0;
          @ decreases top - i;
          @*/
		while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
		return i;
	}
}