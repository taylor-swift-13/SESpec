#include <stdlib.h>
#include <limits.h>

/*@
    requires Array > 0;
    requires \valid(args + (0 .. Array-1));
    assigns \nothing;
    
    /* Recursive helper definitions describing the intended semantics:
       - maxprod_prev(i,p) = maximum of mpis[p']*args[i] for p' in [0..p] such that args[i] > args[p'],
         or INT_MIN if no such p' exists.
       - mpis_val(i) = final value stored in mpis[i] by the algorithm:
           mpis_val(0) = args[0]
           mpis_val(i) = max(args[i], maxprod_prev(i, i-1))
       - max_mpis(i) = maximum of mpis_val(j) for j in [0..i]
    */
    logic integer maxprod_prev(integer i, integer p) =
        p < 0 ? INT_MIN :
        ( args[i] > args[p] ? \max(mpis_val(p) * args[i], maxprod_prev(i, p-1))
                            : maxprod_prev(i, p-1) );

    logic integer mpis_val(integer i) =
        i == 0 ? args[0] : \max(args[i], maxprod_prev(i, i-1));

    logic integer max_mpis(integer i) =
        i == 0 ? mpis_val(0) : \max(mpis_val(i), max_mpis(i-1));

    ensures \result == max_mpis(Array-1);
*/
int maxProduct(int * args, int args_len, int Array) {

		int *mpis = (int *)malloc(sizeof(int) * (Array));
		/*@
		    // We assume malloc succeeds for the verification of the rest of the function.
		    // This allows valid dereferences of mpis[0..Array-1].
		    // (In practice, a NULL check would be required.)
		    assumes mpis != \null;
		    assumes \valid(mpis + (0 .. Array-1));
		*/

		int mpis_len = Array;
		/*@
		    loop invariant 0 <= array <= Array;
		    loop invariant \forall integer j; 0 <= j < array ==> mpis[j] == args[j];
		    loop assigns array, mpis[0..Array-1];
		    loop variant Array - array;
		*/
		for (int array = 0; array < Array; array++) {
			mpis[array] = args[array];
		}

		/* Outer loop: builds mpis values progressively.
		   After each iteration i, mpis[0..i] hold their final values mpis_val(0..i).
		*/
		/*@
		    loop invariant 1 <= i <= Array;
		    loop invariant \forall integer j; 0 <= j < i ==> mpis[j] == mpis_val(j);
		    loop assigns i, mpis[0..Array-1];
		    loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			/* Inner loop: updates mpis[i] by considering predecessors p < i.
			   The invariant states mpis[i] equals the maximum among args[i] and
			   mpis_val(p)*args[i] for p processed so far.
			*/
			/*@
			    loop invariant 0 <= p <= i;
			    loop invariant mpis[i] >= args[i];
			    loop invariant \forall integer q; 0 <= q < p ==> 
			          (args[i] > args[q] ==> mpis[i] >= mpis_val(q) * args[i]);
			    loop invariant \forall integer j; 0 <= j < i ==> mpis[j] == mpis_val(j);
			    loop assigns p, mpis[i];
			    loop variant i - p;
			*/
			for (int p = 0; p < i; p++) {
				if (args[i] > args[p]
						&& mpis[i] < (mpis[p] * args[i])) {
					mpis[i] = mpis[p] * args[i];
				}
			}
		}

		/* Final loop: compute the maximum over mpis[0..Array-1].
		*/
		int num = mpis[0];
		/*@
		    loop invariant 1 <= i <= Array;
		    loop invariant num == max_mpis(i-1);
		    loop assigns i, num;
		    loop variant Array - i;
		*/
		for (int i = 1; i < Array; i++) {
			if (mpis[i] > num) {
				num = mpis[i];
			}
		}
		return num;
}
