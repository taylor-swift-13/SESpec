
/*@
  requires count >= 0;
*/
        
int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            /*@
              loop invariant 1 <= index <= 2 * count + 1;
              loop invariant 0 <= ret;
              loop invariant ret <= (index - 1) * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop invariant count == \at(count,Pre);
              loop assigns index, ret;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant 0 <= ret;
          loop invariant ret <= (index - 1) * (2 * count) + (i - 1);
          loop invariant 1 <= index <= 2 * count + 1;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count,Pre);
          loop assigns ret, i;
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
