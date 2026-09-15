
/*@ predicate sorted_int_array{L}(int *a, integer n) =
      \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
*/
/*@
    requires n >= 0;
    requires n <= args_len;
    requires \valid(args + (0 .. args_len - 1));
    requires sorted_int_array(args, n);
    assigns \nothing;
    ensures -1 <= \result < n;
    ensures \result >= 0 ==> args[\result] == Array;
    ensures \result == -1 ==> \true;
    ensures \result != -1 ==> \exists integer k; 0 <= k < n && args[k] == Array && \result == k;
    ensures \result == -1 ==> \true;
    ensures \result == -1 ==> \true;
*/
int foo218(int * args, int args_len, int Array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant -1 <= hi < n;
          loop invariant i <= hi + 1;
          loop invariant result == -1 || 0 <= result < n;
          loop invariant result == -1 || hi < result;
          loop invariant result == -1 || args[result] == Array;
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant n == \at(n,Pre);
          loop invariant Array == \at(Array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns result, hi, i;
            */
            while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == Array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < Array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
