
/*@
  logic integer count_occ(int *a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 :
    count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo215(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(y,Pre) - 1) ==> (i <= r + 1);
          loop invariant (!(0 <= \at(y,Pre) - 1)) ==> ((p == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          */
            while (i <= r) {
			int tmp = (i + r) / 2;
			if (args[tmp] == x) {
				p = tmp;
				i = tmp + 1;
			} else if (args[tmp] < x) {
				i = tmp + 1;
			} else {
				r = tmp - 1;
			}
		}
            

		return p;
}
