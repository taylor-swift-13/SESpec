
/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */
        
int foo343(int code, int b, int l, int c) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret >= 0;
          loop invariant ret <= loop - l;
          loop invariant c == \at(c,Pre);
          loop invariant l == \at(l,Pre);
          loop invariant b == \at(b,Pre);
          loop invariant code == \at(code,Pre);
          loop assigns loop, ret;
            */
            for (int loop = l; loop <= c; loop++) {
			if (loop % code != 0) {
				ret++;
			}
			if (ret == b) {
				return loop;
			}
		}
            
		return -1;
}
