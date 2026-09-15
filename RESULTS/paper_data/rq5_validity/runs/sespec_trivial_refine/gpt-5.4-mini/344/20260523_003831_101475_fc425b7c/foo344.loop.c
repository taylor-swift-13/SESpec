
        /*@
        logic integer count_nondiv(int a, int b, int code) = 0;
        */
        
int foo344(int code, int b, int l, int m) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant l <= c;
          loop invariant ret <= c - l;
          loop assigns ret, c;
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
