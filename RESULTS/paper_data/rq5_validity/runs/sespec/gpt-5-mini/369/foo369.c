
/*@ 
  /* existence of a witness w in [lo, hi] with w % p == dy */
  logic boolean exists_mod_in_range(integer lo, integer hi, integer p, integer dy) =
    lo <= hi && (\exists integer w; lo <= w <= hi && w % p == dy);

  /* there is a specific witness w in [lo, hi] with w % p == dy and it equals v */
  logic boolean some_mod_value(integer lo, integer hi, integer p, integer dy, integer v) =
    \exists integer w; lo <= w <= hi && w % p == dy && v == w;
*/

/* trivial to keep syntactic relation */
*/
int foo369(int value, int p, int dy) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= \at(value,Pre) + 1;
          loop invariant (c <= \at(value,Pre)) ==> (((result == 0) && (dy == \at(dy,Pre)) && (p == \at(p,Pre)) && (value == \at(value,Pre))) || some_mod_value(1, c-1, \at(p,Pre), \at(dy,Pre), result));
          loop invariant (!(c <= \at(value,Pre))) ==> ((result == 0) && (dy == \at(dy,Pre)) && (p == \at(p,Pre)) && (value == \at(value,Pre)));
          loop invariant dy == \at(dy,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
            
		return result;
}
