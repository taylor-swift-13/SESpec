
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo312(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant ret >= 0;
          loop invariant ret <= (i - 1) * (2 * count);
          loop invariant center == 2 * count * (2 * count);
          loop invariant diameter == 2 * count;
          loop invariant count == \at(count,Pre);
          loop assigns i, c, diagnalLengthSquare, ret;
            */
            for (int i = 1; i <= 2 * count; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= i <= 2 * count + 1;
              loop invariant 1 <= c <= 2 * count + 1;
              loop invariant 0 <= ret <= (i - 1) * (2 * count) + (c - 1);
              loop invariant center == 2 * count * (2 * count);
              loop invariant diameter == 2 * count;
              loop invariant count == \at(count,Pre);
              loop assigns c, diagnalLengthSquare, ret;
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
