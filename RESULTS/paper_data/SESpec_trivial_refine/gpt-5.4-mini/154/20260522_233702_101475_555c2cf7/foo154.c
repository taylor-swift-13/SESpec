
/*@
*/

 /*@
  requires 1 <= Array;
  requires \valid_read(args + (0 .. Array - 1));
  assigns \nothing;
  ensures \forall integer i; 0 <= i < Array ==> \result >= args[i];
  ensures Array == 1 ==> \result == args[0];
  ensures Array > 1 ==> \result >= args[Array - 1];
*/

int foo154(int * args, int args_len, int Array) {

	int *mpis = (int *)malloc(sizeof(int) * (Array));
	int mpis_len = Array;
	
	/*@
	  loop invariant 0 <= array <= Array;
	  loop assigns array, mpis[0 .. Array-1];
	  loop variant Array - array;
	*/
	for (int array = 0; array < Array; array++) {
		mpis[array] = args[array];
	}
	
	/*@
	  loop invariant 1 <= i <= Array;
	  loop assigns i, mpis[i];
	  loop variant Array - i;
	*/
	for (int i = 1; i < Array; i++) {
		/*@
		  loop invariant 0 <= p <= i;
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
			
	int result = mpis[0];
	/*@
	  loop invariant 1 <= i <= Array;
	  loop invariant result >= mpis[0];
	  loop invariant \forall integer k; 0 <= k < i ==> result >= mpis[k];
	  loop assigns i, result;
	  loop variant Array - i;
	*/
	for (int i = 1; i < Array; i++) {
		if (mpis[i] > result) {
			result = mpis[i];
		}
	}
			
	return result;
}
