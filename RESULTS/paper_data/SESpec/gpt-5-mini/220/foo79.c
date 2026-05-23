
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  predicate in_range(int* a, integer len) =
    len >= 0 ==> \valid(a + (0..len-1));
*/

/*@ 
  requires \true;
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires n >= 0;
  requires in_range(args, n);
  assigns \nothing;
  ensures \result >= -1 && \result < n;
  ensures \result == -1 || (0 <= \result && \result < n && args[\result] == array);
*/
int foo79(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant 0 <= i <= n;
          loop invariant -1 <= hi && hi < n;
          loop invariant -1 <= result && result < n;
          loop invariant (result == -1) || (0 <= result && result < n && args[result] == array);
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
