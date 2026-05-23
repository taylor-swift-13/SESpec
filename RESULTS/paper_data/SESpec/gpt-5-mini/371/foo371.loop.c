
/*@
  predicate exists_mod_in_range(integer p, integer z, integer v, integer out_c) =
    (\exists integer c0; 1 <= c0 <= v && c0 % p == z) ==>
      (\exists integer m; 1 <= m <= v && m % p == z &&
         (\forall integer k; 1 <= k < m ==> k % p != z) &&
         out_c == m);
*/

int foo371(int value, int p, int z) {

	int result = 0;
	
        /*@
          loop invariant z == \at(z,Pre);
          loop invariant p == \at(p,Pre);
          loop invariant value == \at(value,Pre);
          loop invariant (result == 0) ==> (\forall integer k; 1 <= k < c ==> k % p != \at(z,Pre));
          loop assigns c, result;
        */
	for (int c = 1; c <= value; c++) {
		if ((c % p) == z) {
			result = c;
		}
	}
		
	return result;
}
