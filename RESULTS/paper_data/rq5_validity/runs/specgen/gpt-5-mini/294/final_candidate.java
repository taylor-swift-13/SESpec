import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetPell {

	/*@ 
	  requires p >= 1;
	  ensures 0 <= \result && \result < 1000000000;
	  ensures (\exists int[] seq; seq != null && seq.length == p + 1
	           && seq[0] == 0
	           && (p >= 1 ==> seq[1] == 1)
	           && (\forall int i; 2 <= i && i <= p; seq[i] == (2*seq[i-1] + seq[i-2]) % 1000000000)
	           && seq[p] == \result);
	@*/
	public static int getPell(int p) {
		int[] arr = new int[p + 1];
		arr[0] = 0;
		arr[1] = 1;
		/*@ 
		  maintaining 2 <= count && count <= p + 1;
		  maintaining arr != null && arr.length == p + 1;
		  maintaining arr[0] == 0;
		  maintaining arr[1] == 1;
		  maintaining (\forall int i; 2 <= i && i < count; arr[i] == (2*arr[i-1] + arr[i-2]) % 1000000000);
		  decreases p - count + 1;
		@*/
		for (int count = 2; count <= p; count++) {
			arr[count] = (2 * arr[count - 1]
					+ arr[count - 2]) % 1000000000;
		}
		return arr[p];
	}
}