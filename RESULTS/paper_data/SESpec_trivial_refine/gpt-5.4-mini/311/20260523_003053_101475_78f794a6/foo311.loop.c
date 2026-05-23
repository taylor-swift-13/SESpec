
        /*@
        */
        
/*@
        logic integer square(integer x) = x * x;
        */
        

int foo311(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \true;
          loop invariant 1 <= index <= 2 * count + 1;
          loop invariant 0 <= result;
          loop assigns result, index;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant 0 <= result;
          loop assigns result, i;
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
