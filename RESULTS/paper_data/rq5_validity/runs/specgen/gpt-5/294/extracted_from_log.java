import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

    /*@ requires p >= 1;
      @ ensures 0 <= \result && \result < 1000000000;
      @ ensures p == 1 ==> \result == 1;
      @*/
	public static int getPell(int p) {
		int[] arr = new int[p + 1];
		arr[0] = 0;
		arr[1] = 1;
        /*@ maintaining 2 <= count && count <= p;
          @ maintaining arr[0] == 0 && arr[1] == 1;
          @ maintaining (\forall int k; 0 <= k && k < count; 0 <= arr[k] && arr[k] < 1000000000);
          @ maintaining (\forall int k; 2 <= k && k < count;
          @                   arr[k] == (2 * arr[k - 1] + arr[k - 2]) % 1000000000);
          @ decreases p - count;
          @*/
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
	}
}