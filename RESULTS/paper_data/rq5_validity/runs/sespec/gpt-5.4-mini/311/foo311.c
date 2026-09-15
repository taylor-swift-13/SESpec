
/*@
  requires count >= 0;
  assigns \nothing;
  ensures count == \at(count, Pre);
  ensures \result >= 0;
  ensures \result <= (2 * count) * (2 * count);
  ensures count == 0 ==> \result == 0;
  ensures count > 0 ==> \result >= 0;
  ensures \result == 0 ==> count >= 0;
  ensures \result > 0 ==> count > 0;
  
*/
int foo311(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
            /*@
          loop invariant 1 <= index <= 2 * count + 1;
          loop invariant result >= 0;
          loop invariant diameter == 2 * count;
          loop invariant center == diameter * diameter;
          loop invariant count == \at(count,Pre);
          loop invariant result <= (index - 1) * (2 * count);
          loop assigns index, result;
            */
            for (int index = 1; index <= 2 * count; index++) {
			
            /*@
          loop invariant 1 <= i <= 2 * count + 1;
          loop invariant result >= 0;
          loop invariant index * index + i * i >= 0;
          loop invariant result <= (index - 1) * (2 * count) + (i - 1);
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
