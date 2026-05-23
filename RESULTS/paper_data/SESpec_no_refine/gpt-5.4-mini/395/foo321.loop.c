
/*@
  logic integer odd_poly(integer c) = 16 * c * c * c * c;
*/

int foo321(int p) {

		int odd = 0;
		
        /*@
          loop invariant 0 <= c;
          loop invariant odd == 16 * (c - 1) * (c - 1) * (c - 1) * (c - 1);
        */
            /*@
          loop invariant (c <= \at(p,Pre)) ==> (odd == 16 * (c - 1) * (c - 1) * (c - 1) * (c - 1));
          loop invariant (!(c <= \at(p,Pre))) ==> ((odd == 0)&&(p == \at(p,Pre)));
          loop invariant p == \at(p,Pre);
          loop assigns c, tmp, odd;
            */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
            
		return odd;
}
