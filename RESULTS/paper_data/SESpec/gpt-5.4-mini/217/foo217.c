

/*@
  requires args_len >= 0;
  requires 0 <= y <= args_len;
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i, j; 0 <= i < j < args_len ==> args[i] <= args[j];
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  assigns \nothing;
  ensures \result >= -1;
  ensures \result == -1 || \result < args_len;
  ensures \result == -1 || args[\result] == x;
*/
int foo217(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
        /*@
          loop invariant i >= 0;
          loop invariant r <= y - 1;
          loop invariant k >= -1;
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant r + 1 <= y;
          loop assigns \nothing;
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
