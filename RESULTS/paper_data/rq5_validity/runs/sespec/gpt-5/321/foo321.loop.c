


int foo321(int n, int y) {

		int ret = 1;
		int r = 1;
		if (n > y) {
			int g = n;
			n = y;
			y = g;
		}
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant ret <= l;
          loop invariant 1 <= ret;

          loop invariant \forall integer k; 1 <= k < l ==> ((n % k == 0 && y % k == 0) ==> ret >= k);
          loop invariant (n % ret == 0) && (y % ret == 0);
          loop invariant \forall integer d; 1 <= d < l ==> ((n % d == 0 && y % d == 0) ==> d <= ret);
          loop invariant (l == 1) ==> (ret == 1);

          loop invariant (l <= \at(y,Pre)) ==> (ret <= \at(y,Pre));
          loop invariant (l <= \at(y,Pre)) ==> ((n % ret == 0) && (y % ret == 0));
          loop invariant (l <= \at(y,Pre)) ==> (((r == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (ret <= l && ret >= 1 && n % ret == 0 && y % ret == 0));
          loop invariant r == 1;
          loop assigns l, ret;
            */
            for (int l = 1; l <= n; l++) {
			if (n % l == 0 && y % l == 0) {
				ret = l;
			}
		}
            
		r = (n * y) / ret;
		return r;
}
