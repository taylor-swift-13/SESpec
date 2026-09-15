
/*@
  requires args_len >= 0;
  requires \valid_read(args + (0..args_len-1));
  requires 0 <= y <= args_len;
  assigns \nothing;
  ensures -1 <= \result < args_len;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \result != -1 ==> args[\result] == x;
*/
int foo215(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		
            
        /*@
          loop invariant 0 <= i <= args_len;
          loop invariant -1 <= r < args_len;
          loop invariant i <= r + 1;
          loop invariant p == -1 || (0 <= p < args_len);
          loop invariant p == -1 || args[p] == x;
          loop invariant p == -1 || p < i || p > r;
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns p, i, r;
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
