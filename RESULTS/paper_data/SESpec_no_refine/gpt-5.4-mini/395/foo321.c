
/*@ 
  assigns \nothing;
  ensures \result == (p <= 0 ? 0 : 16 * p * (p + 1) * (2 * p * p + 2 * p - 1) / 3);
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
