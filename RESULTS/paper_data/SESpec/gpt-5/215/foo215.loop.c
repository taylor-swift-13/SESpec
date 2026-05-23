
int foo215(int * args, int args_len, int x, int y) {

		int i = 0;
		int r = y - 1;
		int p = -1;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= y ==> -1 <= p < y;
          loop invariant 0 <= y ==> (-1 <= r < y) || (r < -1);
          loop invariant 0 <= y ==> 0 <= i <= y;
          loop invariant p == -1 || (0 <= p < y && args[p] == x);
          loop invariant p != -1 ==> (\exists integer k; 0 <= k < y && args[k] == x && k <= p);
          loop invariant (i > r && p != -1) ==> (0 <= p < y && args[p] == x);
          loop invariant (0 <= \at(y,Pre) - 1) ==> (0 <= i && i <= \at(y,Pre) && -1 <= p && p < \at(y,Pre) && r < \at(y,Pre));
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((p == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (0 <= i && i <= \at(y,Pre)));
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((p == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= r && r < \at(y,Pre)));
          loop invariant (0 <= \at(y,Pre) - 1) ==> (((p == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (-1 <= p && p < \at(y,Pre)));
          loop invariant (!(0 <= \at(y,Pre) - 1)) ==> ((p == -1)&&(r == \at(y,Pre) - 1)&&(i == 0)&&(y == \at(y,Pre))&&(x == \at(x,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
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
