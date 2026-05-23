int leftInsertion(int * args, int args_len, int array);

/*@ 
  predicate StrictlyIncreasing(int *a, integer n) =
    \forall integer i, j; 0 <= i < j < n ==> a[i] < a[j];
*/

/*@
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len - 1));
  requires StrictlyIncreasing(args, args_len);
  assigns \nothing;

  behavior present:
    assumes \exists integer j; 0 <= j < args_len && args[j] == array;
    ensures 0 <= \result < args_len;
    ensures args[\result] == array;

  behavior absent:
    assumes \forall integer j; 0 <= j < args_len ==> args[j] != array;
    ensures 0 <= \result <= args_len;
    ensures \forall integer k; 0 <= k < \result ==> args[k] < array;
    ensures \result == args_len || array < args[\result];

  ensures 0 <= \result <= args_len;
  ensures \forall integer k; 0 <= k < \result ==> args[k] < array;
  ensures \forall integer k; \result <= k < args_len ==> array <= args[k];

  complete behaviors present, absent;
  disjoint behaviors present, absent;
*/
int leftInsertion(int * args, int args_len, int array) {

		int result = 0;
		int top = args_len - 1;
		/*@
		  loop invariant 0 <= result <= args_len;
		  loop invariant -1 <= top < args_len;
		  loop invariant result <= top + 1;
		  loop invariant \forall integer k; 0 <= k < result ==> args[k] < array;
		  loop invariant \forall integer k; top < k < args_len ==> array < args[k];
		  loop assigns result, top;
		  loop variant top - result + 1;
		*/
		while (result <= top) {
			int i = (result + top) / 2;
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				result = i + 1;
			} else {
				top = i - 1;
			}
		}
		return result;
}
