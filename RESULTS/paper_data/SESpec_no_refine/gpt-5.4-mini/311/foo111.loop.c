
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo111(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= index <= 2 * count + 1;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant result == 0;
          loop assigns index, result;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= index <= 2 * count + 1;
              loop invariant 1 <= i <= 2 * count + 1;
              loop invariant 0 <= result <= (index - 1) * 2 * count + (i - 1);
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop assigns i, diagnalLengthSquare, result;
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
