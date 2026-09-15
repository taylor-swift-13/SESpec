
/*@
  predicate BIT_SET(integer x, integer i) = (0 <= i) && ((x >> i) & 1) == 1;
*/
        
int foo352(int number) {

		int result = 0;
		int ret = 0;
		int total = number;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant total == \at(number,Pre) >> ret;
          
          loop invariant (\at(number,Pre) >= 0) ==> total >= 0;
          
          loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre)) && (ret == 0) && (result == 0) && (number == \at(number,Pre)));
          
          loop assigns result, total, ret;
            */
            while (total > 0) {
			if (ret % 2 == 0) {
				result = result | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
            
		return number ^ result;
}
