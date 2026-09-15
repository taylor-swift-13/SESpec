
/*@ 
  logic integer binomial(integer n, integer k) =
    k < 0 ? 0 :
    k == 0 ? 1 :
    k > n ? 0 :
    (k == n ? 1 : (n * binomial(n - 1, k - 1)) / k);
*/

/*@
  requires \true;
  assigns \nothing;
*/
int foo284_c375(int num, int p) {

		if (p > num - p)
			p = num - p;
		int b = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num == \at(num,Pre);
          loop assigns r, b;
            */
            for (int r = 1; r <= p; r++) {
			b = b * (num - r + 1) / r;
		}
            
		return b;
}
