
/*@ predicate nondecreasing(int *a, integer lo, integer hi) =
      \forall integer k1, k2; lo <= k1 <= k2 < hi ==> a[k1] <= a[k2]; */

/*@ logic integer count_eq(int *a, integer lo, integer hi, integer v) =
      lo >= hi ? 0 : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0); */

/*@
  requires \valid_read(args + (0 .. args_len-1));
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires 0 <= n <= args_len;
  requires nondecreasing(args, 0, args_len);
  assigns \nothing;
*/
int foo79(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (0 <= i && -1 <= hi && i <= hi + 1 && hi < \at(n,Pre));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i && i <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= hi && hi < \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (result == -1 || (0 <= result && result < \at(n,Pre) && args[result] == array)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop invariant 0 <= i && i <= hi + 1;
          loop invariant -1 <= hi && hi < n;
          loop invariant nondecreasing(args, 0, args_len);
          loop assigns result, hi, i;
            */
            while (i <= hi) {
			int tmp = (i + hi) / 2;
			if (args[tmp] == array) {
				result = tmp;
				hi = tmp - 1;
			} else if (args[tmp] < array) {
				i = tmp + 1;
			} else {
				hi = tmp - 1;
			}
		}
            
		return result;
}
