int leftInsertion(int * args, int args_len, int array);

/*@ 
  requires args_len >= 0;
  requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
  assigns \nothing;
  ensures 0 <= \result <= args_len;

  behavior found:
    assumes \exists integer k; 0 <= k < args_len && args[k] == array;
    ensures 0 <= \result < args_len && args[\result] == array;

  behavior not_found:
    assumes \forall integer k; 0 <= k < args_len ==> args[k] != array;
    ensures \forall integer k; 0 <= k < \result ==> args[k] < array;
    ensures \forall integer k; \result <= k < args_len ==> args[k] > array;

  complete behaviors;
  disjoint behaviors;
*/
int leftInsertion(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		  loop invariant 0 <= ret <= args_len;
		  loop invariant -1 <= top <= args_len - 1;
		  loop invariant ret <= top + 1;
		  loop invariant \forall integer k; 0 <= k < ret ==> args[k] < array;
		  loop invariant \forall integer k; top < k < args_len ==> args[k] > array;
		  loop assigns ret, top;
		  loop variant top - ret + 1;
		*/
		while (ret <= top) {
			int i = (ret + top) / 2;
			/*@ assert ret <= i <= top; */
			/*@ assert 0 <= i < args_len; */
			if (args[i] == array) {
				return i;
			} else if (args[i] < array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
