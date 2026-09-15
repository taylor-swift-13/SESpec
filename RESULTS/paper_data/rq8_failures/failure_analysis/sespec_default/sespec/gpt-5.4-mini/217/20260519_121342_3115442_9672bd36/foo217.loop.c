
/*@ logic boolean in_bounds(integer i, integer n) = 0 <= i < n; */

int foo217(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int k = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (i <= r + 1));
          loop invariant (!(0 <= \at(y,Pre) - 1)) ==> ((k == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
