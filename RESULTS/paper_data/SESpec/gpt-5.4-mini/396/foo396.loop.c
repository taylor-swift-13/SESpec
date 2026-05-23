
/*@
  logic integer sum4(integer n) =
    n <= 0 ? 0 : sum4(n - 1) + n * n * n * n;
*/

int foo396(int p) {

		int even = 0;
		
            
        /*@
          loop invariant 1 <= c;
          loop invariant c <= \at(p,Pre) + 1 || \at(p,Pre) < 0;
          loop invariant even == 16 * sum4(c - 1);
          loop invariant (c <= \at(p,Pre)) ==> (even == 16 * sum4(c - 1)) ;
          loop invariant p == \at(p,Pre);
          loop assigns c, even;
            */
            for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
