
/*@
*/

        
/*@
*/
        

int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop invariant count == \at(count,Pre);
              loop invariant 1 <= index <= 2 * count + 1;
              loop assigns index, i, diagnalLengthSquare, ret;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= index <= 2 * count;
              loop assigns ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
				int diagnalLengthSquare = (index * index + i * i);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
