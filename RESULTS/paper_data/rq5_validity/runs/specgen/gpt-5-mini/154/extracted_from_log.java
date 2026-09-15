import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class MaxProduct {

	/*@ 
	  @ requires args != null;
	  @ requires 0 <= Array && Array <= args.length;
	  @ 
	  @ // Result is at least every single element
	  @ ensures (\forall int i; 0 <= i && i < Array; result >= args[i]);
	  @ 
	  @ // There exists an array mpisFinal that corresponds to the values computed by the algorithm,
	  @ // and the result is the maximum value in that array.
	  @ ensures (\exists int[] mpisFinal;
	  @            mpisFinal != null &&
	  @            mpisFinal.length == Array &&
	  @            // initial copy: mpisFinal[array] == args[array] for all indices
	  @            (\forall int array; 0 <= array && array < Array; mpisFinal[array] == args[array])
	  @            &&
	  @            // recurrence: for each i, mpisFinal[i] is at least args[i],
	  @            // and for every p < i with args[i] > args[p], mpisFinal[i] >= mpisFinal[p] * args[i]
	  @            && (\forall int i; 1 <= i && i < Array;
	  @                  mpisFinal[i] >= args[i]
	  @                  && (\forall int p; 0 <= p && p < i;
	  @                        (args[i] > args[p]) ==> (mpisFinal[i] >= mpisFinal[p] * args[i])
	  @                     )
	  @               )
	  @            &&
	  @            // result is the maximum of mpisFinal
	  @            result == (\max int j; 0 <= j && j < Array; mpisFinal[j])
	  @         );
	  @*/
	public static int maxProduct(int[] args, int Array) {
		int[] mpis = new int[Array];
		/*@ 
		  @ // loop 1: copy initial values
		  @ maintaining 0 <= array && array <= Array;
		  @ maintaining (\forall int k; 0 <= k && k < array; mpis[k] == args[k]);
		  @ decreases Array - array;
		  @*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}
		/*@ 
		  @ // outer loop over i: maintain that for all indices < i the mpis entries are >= args entries
		  @ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int k; 0 <= k && k < i; mpis[k] >= args[k]);
		  @ decreases Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			/*@ 
			  @ // inner loop over p: bounds and a monotonicity property for mpis[i]
			  @ maintaining 0 <= p && p <= i;
			  @ maintaining (\forall int k; 0 <= k && k < i; mpis[k] >= args[k]);
			  @ // For processed p, mpis[i] is at least any candidate mpis[p]*args[i] when args[i] > args[p]
			  @ maintaining (\forall int q; 0 <= q && q < p; (args[i] > args[q]) ==> (mpis[i] >= mpis[q] * args[i]));
			  @ decreases i - p;
			  @*/
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}
		int result = mpis[0];
		/*@ 
		  @ // final loop: compute maximum
		  @ maintaining 1 <= i && i <= Array;
		  @ maintaining (\forall int k; 0 <= k && k < i; result >= mpis[k]);
		  @ decreases Array - i;
		  @*/
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > result) {
				result = mpis[i];
			}
		}
		return result;
	}
}