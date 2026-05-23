
/*@ predicate all_equal{L}(int *args, integer lo, integer hi, integer v) =
      lo >= hi ? 1
               : (args[lo] == v && all_equal(args, lo + 1, hi, v));
*/

int foo76(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
            
        /*@
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i <= r + 1));
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= k < args_len));
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (k == -1 || args[k] == x));
          loop invariant (!(0 <= \at(y,Pre) - 1)) ==> ((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant 0 <= \at(args_len,Pre);
          loop invariant \at(args_len,Pre) < 100;
          loop invariant \at(args_len,Pre) > 0;
          loop invariant \valid_read(args + (0 .. args_len - 1));
          loop invariant \forall integer t; 0 <= t < args_len ==> args[t] == \at(args[t], Pre);
          loop assigns tmp, k, i, r;
            */
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				k = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}
            

		return k;
}
