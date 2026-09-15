
/*@
*/

        
/*@ logic integer count_points(integer c) =
      \sum(integer idx = 1; idx <= 2*c; idx++) (
        \sum(integer j = 1; j <= 2*c; j++) (
          (idx*idx + j*j <= (2*c)*(2*c) ? 1 : 0)
        )
      ); */
/*@
  assigns \nothing;
  ensures \result == count_points(count);
*/
int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            /*@
              loop invariant diameter == 2 * count;
              loop invariant center == diameter * diameter;
              loop invariant count == \at(count,Pre);
              loop invariant 1 <= index <= 2 * count + 1;
              loop assigns index, i, diagnalLengthSquare, ret;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
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
