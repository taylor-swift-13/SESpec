
/*@
  logic integer binom(integer n, integer k) =
    k < 0 || k > n ? 0 :
    k == 0 ? 1 :
    n * binom(n-1, k-1) / k;
*/

/*@
  requires \true;
  assigns \nothing;
*/
int foo375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		
        /*@
          loop invariant r >= 1;
          loop invariant (p >= 0) ==> (r <= p + 1);
          loop invariant r != 0;
          loop invariant (r - 1) >= 0;
          loop assigns r, b;
        */
        for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
            
		return b;
}
