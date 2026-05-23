int findMissing(int * args, int args_len, int array);

 /*@
    requires args_len >= 0;
    requires array >= 0;
    requires array <= args_len;
    requires (array == 0 || \valid(args + (0 .. array-1)));
    assigns \nothing;

    behavior small_array:
      assumes array == 0 || array == 1;
      ensures \result == 1;

    behavior normal_array:
      assumes array >= 2;
      /* If there exists an index k in 1..array with args[k-1] != k,
         the function returns the smallest such index */
      ensures (\exists integer k; 1 <= k <= array && args[k-1] != k) ==>
              (\result >= 1 && \result <= array &&
               args[\result-1] != \result &&
               \forall integer j; 1 <= j < \result ==> args[j-1] == j);
      /* If all entries match, the function returns array */
      ensures (\forall integer j; 1 <= j <= array ==> args[j-1] == j) ==> \result == array;

    complete behaviors small_array, normal_array;
    disjoint behaviors small_array, normal_array;
 */
int findMissing(int * args, int args_len, int array) {

		int find = 1;
		if (array == 0 || array == 1) {
			return find;
		}
		/*@
		    loop invariant 1 <= remaining <= array + 1;
		    loop invariant \forall integer j; 1 <= j < remaining ==> args[j-1] == j;
		    loop assigns remaining, find;
		    loop variant array - remaining + 1;
		*/
		for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				find = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return find;
}
