
/*@
  assigns \nothing;
  ensures \result == 0;
*/
int foo323(int p) {

		int even = 0;
		
            /*@
          loop invariant 1 <= c <= p + 1;
          loop invariant p == \at(p,Pre);
          loop invariant even == 0;
          loop invariant (c <= \at(p,Pre)) ==> (even == 0);
          loop invariant (!(c <= \at(p,Pre))) ==> ((even == 0)&&(p == \at(p,Pre)));
          loop assigns c, tmp, even;
            */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			even = even + (tmp * tmp * tmp * tmp);
		}
            
		return even;
}
