
/*@
predicate is_even(integer x) = x % 2 == 0;
*/

int foo350(int num) {

		int result = 0;
		int ret = 0;
		int total = num;
		
        /*@ 
          loop invariant 0 <= ret;
          loop invariant num <= 0 || ret <= num;
          loop invariant 0 <= total;
          loop invariant num <= 0 || total <= num;
          loop invariant 0 <= result;
          loop assigns result, ret, total;
        */
            /*@
          loop invariant PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS;
          */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return num ^ result;
}
