
/*@
  // no extra predicates or logic functions needed
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (\result == -1) || (0 <= \result && \result < y);
  ensures (y <= 0) ==> (\result == -1);
*/
int foo217(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant y == y;
          loop invariant x == x;
          loop invariant args_len == args_len;
          loop invariant args == args;
          loop invariant (0 <= y - 1) ==> (0 <= i && -1 <= r && i <= y && r < y);
          loop invariant (k == -1) || (0 <= k && k < y);
          loop invariant (i > r) ==> (k == -1 || (0 <= k && k < y));
          loop assigns k, i, r;
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
