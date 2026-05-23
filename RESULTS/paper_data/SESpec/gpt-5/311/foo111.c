
/*@ logic integer foo111_pair_count(integer c, integer idx, integer i) =
      (idx > 2*c) ? 0 :
      ((i > 2*c) ? foo111_pair_count(c, idx + 1, 1)
                 : ((idx*idx + i*i <= (2*c)*(2*c) ? 1 : 0) + foo111_pair_count(c, idx, i + 1))); */
/*@
  requires count >= 0;
  requires count <= 23170;
  assigns \nothing;
*/
int foo111(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= index;
          loop invariant center == (2 * count) * (2 * count);
          loop invariant diameter == 2 * count;
          loop invariant result >= 0;
          loop assigns index, result;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= i <= 2 * count + 1;
              loop invariant 1 <= index && index <= 2 * count;
              loop invariant result >= 0;
              loop invariant center == (2 * count) * (2 * count);
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
