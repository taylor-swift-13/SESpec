
/*@
  predicate not_in_range(int *a, integer lo, integer hi, integer v) =
    \forall integer k; lo <= k <= hi ==> a[k] != v;
*/

/*@
  predicate nondecreasing(int *a, integer lo, integer hi) =
    \forall integer i, j; lo <= i <= j < hi ==> a[i] <= a[j];
*/

/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires nondecreasing(args, 0, args_len);
  assigns \nothing;
  ensures 0 <= \result <= args_len;
*/
int foo119(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
            /*@
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant 0 <= ret <= \at(args_len,Pre);
          loop invariant -1 <= top <= \at(args_len,Pre) - 1;
          loop invariant top + 1 <= \at(args_len,Pre);
          loop assigns ret, top;
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
