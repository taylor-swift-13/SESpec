
/*@
  assigns \nothing;
  
  ensures \result >= 0;
  ensures count < 1 ==> \result == 0;
*/
int foo312(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count == \at(count,Pre);
          loop invariant diameter == 2 * \at(count,Pre);
          loop invariant center == 2 * \at(count,Pre) * (2 * \at(count,Pre));
          loop invariant 1 <= i;
          loop invariant 0 <= ret;
          loop invariant ret <= (i - 1) * (2 * \at(count,Pre));
          loop invariant (i <= 2 * \at(count,Pre)) ==> (ret >= 0);
          loop invariant (i <= 2 * \at(count,Pre)) ==> (ret <= (i - 1) * (2 * \at(count,Pre)));
          loop invariant (!(i <= 2 * \at(count,Pre))) ==> (ret <= (2 * \at(count,Pre)) * (2 * \at(count,Pre)));
          loop assigns i, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= ret;
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret <= (i - 1) * (2 * count) + (c - 1);
          loop assigns c, ret;
            */
            for (int c = 1; c <= 2 * count; c++) {
				int diagnalLengthSquare = (i * i + c * c);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
