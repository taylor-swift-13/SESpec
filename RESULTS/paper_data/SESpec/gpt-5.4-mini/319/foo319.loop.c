
/*@ requires n > y; */


int foo319(int n, int y) {

		int ret = 1;
		int l = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 1 <= j;
          loop invariant ret >= 1;
          loop invariant ret <= j;
          loop invariant n % ret == 0;
          loop invariant y % ret == 0;
          loop invariant \forall integer k; 1 <= k < j && n % k == 0 && y % k == 0 ==> k <= ret;
          loop invariant n == \at(y,Pre);
          loop invariant y == \at(n,Pre);
          loop invariant l == 1;
          loop assigns j, ret;
        */
        for (int j = 1; j <= n; j++) {
			if (n % j == 0 && y % j == 0) {
				ret = j;
			}
		}
            
		l = (n * y) / ret;
		return l;
}
