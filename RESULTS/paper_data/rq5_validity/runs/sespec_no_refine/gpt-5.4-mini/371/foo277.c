
/*@ 
  assigns \nothing;
  ensures \result == (
    (\at(value, Pre) < 1) ?
      0 :
      (
        exists integer c; 1 <= c && c <= \at(value, Pre) && (c % \at(p, Pre)) == \at(z, Pre) &&
        (\forall integer d; 1 <= d && d <= \at(value, Pre) && d > c ==> (d % \at(p, Pre)) != \at(z, Pre))
      ) ? 
        (let integer m = \at(value, Pre);
         (exists integer c; 1 <= c && c <= m && (c % \at(p, Pre)) == \at(z, Pre) &&
          (\forall integer d; 1 <= d && d <= m && d > c ==> (d % \at(p, Pre)) != \at(z, Pre))
         ) ? c : 0)
      : 0
  );
*/
int foo277(int value, int p, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant z == \at(z,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
            
		return result;
}
