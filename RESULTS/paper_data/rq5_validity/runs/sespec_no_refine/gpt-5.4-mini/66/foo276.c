
/*@ 
  assigns \nothing;
  ensures \result == 0 || (1 <= \result && \result <= value && PLACE_HOLDER_result(\result, k, z));
  ensures value < 1 ==> \result == 0;
  ensures value >= 1 ==> (\result == 0 || (1 <= \result && \result <= value));
*/
int foo276(int value, int k, int z) {

		int result = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
