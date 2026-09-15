
/*@
  logic integer squaresum(integer x, integer y) = x * x + y * y;
*/

int foo311(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant center == 2 * \at(count,Pre) * (2 * \at(count,Pre));
          loop invariant diameter == 2 * \at(count,Pre);
          loop invariant count == \at(count,Pre);
          loop assigns index, result;
        */
        for (int index = 1; index <= 2 * count; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant count == \at(count,Pre);
            loop invariant diameter == 2 * \at(count,Pre);
            loop invariant center == diameter * diameter;
            loop assigns i, result;
            */
            for (int i = 1; i <= 2 * count; i++) {
				int diagnalLengthSquare = (index * index + i * i);
				if (diagnalLengthSquare <= center) {
					result++;
				}
			}
            
		}
            
		return result;
}
