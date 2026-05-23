
/*@
*/

/*@ 
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
          loop invariant ret >= 0;
          loop assigns i, c, diagnalLengthSquare, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= 2 * count;
          loop invariant 1 <= c <= 2 * count + 1;
          loop invariant ret >= 0;
          loop assigns ret, c;
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
