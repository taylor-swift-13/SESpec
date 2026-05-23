
/*@
  logic integer count_occ(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo79(int * args, int args_len, int array, int n) {

		int i = 0;
		int hi = n - 1;
		int result = -1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i <= hi + 1));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= hi < n));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (result == -1 || args[result] == array));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(hi == \at(n,Pre) - 1)&&(i == 0)&&(n == \at(n,Pre))&&(array == \at(array,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \valid_read(args + (0 .. args_len - 1));
          loop assigns tmp, result, hi, i;
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
