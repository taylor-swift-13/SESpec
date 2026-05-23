
/*@
  logic integer coeff(integer n, integer k) =
    k <= 0 ? 1 :
    n < k ? 0 :
    coeff(n - 1, k - 1) * n / k;
*/

/*@
  requires 0 <= m;
  requires m <= seed;
  assigns \nothing;
  ensures \true;
  ensures \old(m) <= seed - \old(m) ==> m == \old(m);
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
          loop invariant \true;
          loop invariant \true;
          loop invariant \true;
          loop assigns r, b;
            */
            for (int r = 1; r <= m; r++) {
			b = b * (seed - r + 1) / r;
		}
            
		return b;
}
