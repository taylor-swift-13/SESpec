
/*@ logic integer coeff(integer n, integer k) =
      k <= 0 ? 1 : coeff(n, k - 1) * (n - k + 1) / k;
*/

int foo376(int seed, int m) {
        /*@
          requires 0 <= m;
          requires m <= seed;
          
        */

		if (m > seed - m)
			m = seed - m;
		int b = 1;
		
            /*@
          loop invariant 1 <= r;
          loop invariant seed == \at(seed,Pre);
          loop invariant m <= \at(m,Pre);
          loop invariant b == coeff(seed, r - 1);
          loop invariant (r <= m) ==> (b == coeff(seed, r - 1));
          loop invariant (r > m) ==> (b == coeff(seed, m));
          loop assigns r, b;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
