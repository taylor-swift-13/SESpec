import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountWays {

	/*@ public normal_behavior
	  @   requires count >= 1;
	  @   ensures (\exists int[] arrSeq; \exists int[] CSeq;
	  @               arrSeq.length == count + 1
	  @            && CSeq.length == count + 1
	  @            && arrSeq[0] == 1
	  @            && arrSeq[1] == 0
	  @            && CSeq[0] == 0
	  @            && CSeq[1] == 1
	  @            && (\forall int w; 2 <= w && w <= count;
	  @                   arrSeq[w] == arrSeq[w-2] + 2 * CSeq[w-1]
	  @                && CSeq[w] == arrSeq[w-1] + CSeq[w-2])
	  @            && \result == arrSeq[count]);
	  @*/
	public static int countWays(int count) {
		int[] arr = new int[count + 1];
		int[] C = new int[count + 1];
		arr[0] = 1;
		arr[1] = 0;
		C[0] = 0;
		C[1] = 1;
		/*@
		  @   maintaining arr.length == count + 1 && C.length == count + 1;
		  @   maintaining arr[0] == 1 && arr[1] == 0 && C[0] == 0 && C[1] == 1;
		  @   maintaining (\forall int k; 2 <= k && k < w;
		  @                 arr[k] == arr[k-2] + 2 * C[k-1]
		  @              && C[k] == arr[k-1] + C[k-2]);
		  @   decreases count - w + 1;
		  @*/
		for (int w = 2; w <= count; w++) {
			arr[w] = arr[w - 2]
					+ 2 * C[w - 1];
			C[w] = arr[w - 1] + C[w - 2];
		}
		return arr[count];
	}
}