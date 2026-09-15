int findMissing(int * args, int args_len, int array);

/*@ 
  requires args_len >= 0;
  requires array >= 0;
  requires array <= args_len;
  requires \valid_read(args + (0 .. args_len-1));

  assigns \nothing;

  ensures \result >= 1;

  behavior small:
    assumes array <= 1;
    ensures \result == 1;

  behavior mismatch:
    assumes array >= 2;
    assumes \exists integer k; 1 <= k <= array && args[k-1] != k;
    ensures 1 <= \result <= array;
    ensures args[\result - 1] != \result;
    ensures \forall integer j; 1 <= j < \result ==> args[j-1] == j;

  behavior all_match:
    assumes array >= 2;
    assumes \forall integer k; 1 <= k <= array ==> args[k-1] == k;
    ensures \result == array;

  disjoint behaviors;
  complete behaviors;
*/
int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
		  loop invariant 1 <= remaining <= array + 1;
		  loop invariant remaining == 1 ==> found == 1;
		  loop invariant remaining >= 2 ==> found == remaining - 1;
		  loop invariant \forall integer j; 1 <= j < remaining ==> args[j-1] == j;
		  loop assigns found, remaining;
		  loop variant array - remaining + 1;
		*/
		for (int remaining = 1; remaining <= array; remaining++) {
			if (args[remaining - 1] == remaining) {
				found = remaining;
			} else if (args[remaining - 1] != remaining) {
				return remaining;
			}
		}
		return found;
}
