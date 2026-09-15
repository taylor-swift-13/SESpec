
/*@
  assigns \nothing;
*/
int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
        /*@
          loop assigns index, ret;
        */
            for (int index = 1; index <= 2 * count; index++) {
			
            /*@
              loop variant 2 * count - i + 1;
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
