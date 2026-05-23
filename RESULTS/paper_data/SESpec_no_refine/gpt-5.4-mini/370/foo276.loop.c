
/*@ logic integer PLACE_HOLDER_result(integer c, integer value, integer k, integer z) = (c == value); */

int foo276(int value, int k, int z) {

		int result = 0;
		
            
        /*@
          loop invariant (c <= \at(value,Pre)) ==> (((result == 0)&&(z == \at(z,Pre))&&(k == \at(k,Pre))&&(value == \at(value,Pre))) || (PLACE_HOLDER_result));
          loop invariant (!(c <= \at(value,Pre))) ==> ((result == 0)&&(z == \at(z,Pre))&&(k == \at(k,Pre))&&(value == \at(value,Pre)));
          loop invariant z == \at(z,Pre);
          loop invariant k == \at(k,Pre);
          loop invariant value == \at(value,Pre);
          loop assigns c, result;
            */
            for (int c = 1; c <= value; c++) {
			if ((c % k) == z) {
				result = c;
			}
		}
            
		return result;
}
