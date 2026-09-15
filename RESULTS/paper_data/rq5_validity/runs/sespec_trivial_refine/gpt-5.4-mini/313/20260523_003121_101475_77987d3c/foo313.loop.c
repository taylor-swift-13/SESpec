
/*@ predicate nonnegative(integer x) = x >= 0; */
        
/*@ logic integer square(integer x) = x * x; */
        

int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant nonnegative(ret);
          loop invariant nonnegative(index);
          loop assigns ret, index;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant nonnegative(ret);
          loop invariant nonnegative(i);
          loop assigns ret, i, diagnalLengthSquare;
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
