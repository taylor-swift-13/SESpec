
int foo313(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		
        /*@
          loop invariant count == \at(count,Pre);
          loop invariant diameter == 2 * \at(count,Pre);
          loop invariant center == 2 * \at(count,Pre) * (2 * \at(count,Pre));
          loop invariant 1 <= index <= 2 * \at(count,Pre) + 1;
          loop invariant 0 <= ret;
          loop invariant ret <= (index - 1) * 2 * \at(count,Pre);
          loop assigns index, ret;
        */
            for (int index = 1; index <= 2 * count; index++) {
			
            /*@
              loop invariant 1 <= i <= 2 * count + 1;
              loop invariant 0 <= ret <= (index - 1) * 2 * count + (i - 1);
              loop assigns i, diagnalLengthSquare, ret;
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
