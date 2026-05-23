
        /*@
        requires count >= 2;
        */
        

int foo270(int count, int m) {

		int w = 1000000007;
		int *div = (int *)malloc(sizeof(int) * (count + 1));
int div_len = count + 1;
		div[0] = 1;
		div[1] = m;
		div[2] = m * m;
		
            
        /*@
          loop assigns d, div[3..count];
          loop invariant 3 <= d <= count + 1;
          loop invariant div[0] == 1;
          loop invariant div[1] == m;
          loop invariant div[2] == m * m;
          loop invariant \forall integer k; 3 <= k < d ==> div[k] == ((m - 1) * (div[k - 1] + div[k - 2])) % w;
        */
            for (int d = 3; d <= count; d++) {
			div[d] = ((m - 1)
					* (div[d - 1] + div[d - 2])) % w;
		}
            
		return div[count];
}
