
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo215(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= \at(y,Pre);
          loop invariant -1 <= r < \at(y,Pre);
          loop invariant p >= -1 && (p != -1 ==> (0 <= p && p < \at(y,Pre) && args[p] == \at(x,Pre)));
          loop invariant \forall integer k; 0 <= k < \at(y,Pre) ==> args[k] == \at(args[k], Pre);
          loop assigns tmp, p, i, r;
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
