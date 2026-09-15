
/*@
  predicate matches_mod(integer x, integer k, integer z) =
    k != 0 && (x % k) == z;

  logic integer last_match_upto(integer c, integer k, integer z) =
    (c < 1) ? 0 :
    (exists integer x; 1 <= x <= c && matches_mod(x,k,z)) ?
      (max{ integer x | 1 <= x <= c && matches_mod(x,k,z) }) :
      0;
*/
        
int foo370(int value, int k, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= \at(value,Pre) + 1;
          loop invariant z == \at(z,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant value == \at(value,Pre);
          loop invariant result == last_match_upto(c-1, \at(k,Pre), \at(z,Pre));
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
            
		return result;
}
