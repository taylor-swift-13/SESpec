
/*@ predicate divisible(integer x, integer y) = y != 0 && x % y == 0; */

int foo344(int code, int b, int l, int m) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant c >= l;
          loop invariant 0 <= ret;
          loop invariant ret <= c - l;
          loop invariant m == \at(m,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop assigns c, ret;
            */
            for (int c = l; c <= m; c++) {
			if (c % code != 0) {
				ret++;
			}
			if (ret == b) {
				return c;
			}
		}
            
		return -1;
}
