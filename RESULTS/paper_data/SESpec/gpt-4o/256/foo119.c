
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  logic integer max{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] > max(a, lo, hi - 1) ? a[hi - 1] : max(a, lo, hi - 1));
*/

/*@
  logic integer min{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] < min(a, lo, hi - 1) ? a[hi - 1] : min(a, lo, hi - 1));
*/

/*@
  predicate array_unchanged{L1,L2}(int* a, integer n) =
    \forall integer i; 0 <= i < n ==> \at(a[i],L1) == \at(a[i],L2);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
  assigns \nothing;
  ensures \result >= 0 && \result <= args_len;
*/
int foo119(int * args, int args_len, int Array) {

		int ret = 0;
		int top = args_len - 1;
		
        /*@
          loop invariant 0 <= ret && ret <= args_len;
          loop invariant -1 <= top && top < args_len;
          loop invariant ret <= top + 1;
          loop invariant \forall integer i; 0 <= i < args_len ==> args[i] == \at(args[i], Pre);
          loop invariant \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
          loop assigns ret, top;
          loop variant top - ret;
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
