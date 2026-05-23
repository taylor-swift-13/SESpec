
/*@
predicate divides(integer a, integer b) = a != 0 && b % a == 0;
*/

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
          loop invariant 1 <= ret <= j;
          loop invariant divides(ret, n) && divides(ret, y);
          loop invariant \forall integer k; 1 <= k < j ==> (divides(k, n) && divides(k, y) ==> k <= ret);
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
