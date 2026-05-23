
/*@
*/

/*@ logic integer count_y(integer x, integer c, integer y) =
      y <= 0 ? 0 :
      ( (x*x + y*y <= (2*c)*(2*c) ? 1 : 0) + count_y(x, c, y-1) ); */
/*@ logic integer count_xy(integer x, integer c) =
      x <= 0 ? 0 :
      ( count_y(x, c, 2*c) + count_xy(x-1, c) ); */
/*@ logic integer points_leq_circle(integer c) = count_xy(2*c, c); */
/*@
  assigns \nothing;
  ensures \result == points_leq_circle(count);
*/
int foo311(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant count == \at(count,Pre);
              loop invariant diameter == 2 * \at(count,Pre);
              loop invariant center == (2 * \at(count,Pre)) * (2 * \at(count,Pre));
              loop invariant 1 <= index <= 2 * \at(count,Pre) + 1;
              loop invariant 0 <= result;
              loop assigns index, i, diagnalLengthSquare, result;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= index <= 2 * count;
              loop invariant 1 <= i <= 2 * count + 1;
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
