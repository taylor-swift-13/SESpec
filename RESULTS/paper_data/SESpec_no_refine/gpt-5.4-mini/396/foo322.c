
/*@ 
  assigns \nothing;
  ensures \result == (p <= 0 ? 0 : (p * (p + 1) * (2 * p + 1) * (3 * p * p + 3 * p - 1)) );
*/
int foo322(int p) {
		int even = 0;
		
        /*@
          loop invariant 1 <= c <= p + 1;
          loop invariant p == \at(p,Pre);
          loop invariant (c <= \at(p,Pre)) ==> (even % 2 == 0);
          loop invariant (!(c <= \at(p,Pre))) ==> ((even == 0) && (p == \at(p,Pre)));
          loop assigns c, count, even;
        */
        for (int c = 1; c <= p; c++) {
			int count = 2 * c;
			even = even + (count * count * count * count);
		}
            
		return even;
}
