int findMissing(int * args, int args_len, int array);

 /*@
    requires array >= 0;
    requires args_len >= array;
    requires array > 0 ==> \valid(args + (0..array-1));
    assigns \nothing;
    behavior small_array:
        assumes array <= 1;
        ensures \result == 1;
    behavior large_array:
        assumes array > 1;
        ensures 1 <= \result <= array;
        ensures (\forall integer j; 1 <= j <= array ==> args[j-1] == j) ==> \result == array;
        ensures (\exists integer k; 1 <= k <= array && args[k-1] != k) ==>
                (\forall integer j; 1 <= j < \result ==> args[j-1] == j) && args[\result-1] != \result;
    complete behaviors small_array, large_array;
    disjoint behaviors small_array, large_array;
 */
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		    loop invariant 1 <= num <= array + 1;
		    loop invariant 1 <= found <= array;
		    loop invariant \forall integer j; 1 <= j < num ==> args[j-1] == j;
		    loop assigns found, num;
		    loop variant array - num + 1;
		*/
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
}
