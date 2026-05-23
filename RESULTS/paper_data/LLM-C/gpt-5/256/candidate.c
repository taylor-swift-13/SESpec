int leftInsertion(int * args, int args_len, int Array);

 /*@
   requires args_len >= 0;
   requires args_len == 0 || \valid_read(args + (0 .. args_len-1));
   requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
   assigns \nothing;
   ensures 0 <= \result <= args_len;

   behavior found:
     assumes \exists integer k; 0 <= k < args_len && args[k] == Array;
     ensures 0 <= \result < args_len;
     ensures args[\result] == Array;

   behavior not_found:
     assumes \forall integer k; 0 <= k < args_len ==> args[k] != Array;
     ensures \forall integer k; 0 <= k < \result ==> args[k] < Array;
     ensures \forall integer k; \result <= k < args_len ==> args[k] > Array;

   complete behaviors;
   disjoint behaviors;
 */
int leftInsertion(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		/*@
		  loop invariant 0 <= ret <= args_len;
		  loop invariant -1 <= top <= args_len - 1;
		  loop invariant ret <= top + 1;
		  loop invariant \forall integer k; 0 <= k < ret ==> args[k] < Array;
		  loop invariant \forall integer k; top < k < args_len ==> args[k] > Array;
		  loop assigns ret, top;
		  loop variant top - ret + 1;
		*/
		while (ret <= top) {
			int i = (ret + top) / 2;
			if (args[i] == Array) {
				return i;
			} else if (args[i] < Array) {
				ret = i + 1;
			} else {
				top = i - 1;
			}
		}
		return ret;
}
