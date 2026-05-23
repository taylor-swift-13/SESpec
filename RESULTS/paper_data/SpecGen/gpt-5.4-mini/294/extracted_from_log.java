import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	/*@ public normal_behavior
	  @ requires p >= 1;
	  @ ensures 0 <= \result;
	  @ ensures \result < 1000000000;
	  @*/
	public static int getPell(int p) {
		int[] arr = new int[p + 1];
		arr[0] = 0;
		arr[1] = 1;
		/*@ maintaining 2 <= count && count <= p + 1;
		  @ maintaining arr.length == p + 1;
		  @ maintaining arr[0] == 0;
		  @ maintaining arr[1] == 1;
		  @ maintaining (\forall int i; 2 <= i && i < count; 0 <= arr[i] && arr[i] < 1000000000);
		  @ decreases p - count + 1;
		  @*/
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
	}
}