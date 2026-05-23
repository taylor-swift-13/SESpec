/*@
    requires args_len >= 0;
    requires args_len == 0 || \valid(args + (0 .. args_len-1));
    requires \forall integer i; 0 <= i < args_len-1 ==> args[i] <= args[i+1];
    assigns \nothing;
    ensures 0 <= \result <= args_len;
    behavior found:
        assumes \exists integer k; 0 <= k < args_len && args[k] == array;
        ensures 0 <= \result < args_len;
        ensures args[\result] == array;
    behavior not_found:
        assumes !(\exists integer k; 0 <= k < args_len && args[k] == array);
        ensures \forall integer j; 0 <= j < \result ==> args[j] < array;
        ensures \forall integer j; \result <= j < args_len ==> args[j] > array;
    complete behaviors found, not_found;
    disjoint behaviors found, not_found;
*/
int leftInsertion(int * args, int args_len, int array);

int leftInsertion(int * args, int args_len, int array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		    loop invariant 0 <= ret <= args_len;
		    loop invariant -1 <= top < args_len;
		    loop invariant \forall integer k; 0 <= k < ret ==> args[k] < array;
		    loop invariant \forall integer k; top < k < args_len ==> args[k] > array;
		    loop assigns ret, top;
		    loop variant top - ret + 1;
		*/
		while (ret <= top) {
			int i = (ret + top) / 2;
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
