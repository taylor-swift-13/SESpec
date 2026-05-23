int countRectangles(int count);

/*@
    requires count >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 
        \sum integer ii; 1 <= ii <= 2*count; 
            (\sum integer jj; 1 <= jj <= 2*count; ((ii*ii + jj*jj) <= (2*count)*(2*count) ? 1 : 0));
*/
int countRectangles(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		    loop invariant 1 <= index <= 2*count + 1;
		    loop invariant result == 
		        \sum integer ii; 1 <= ii < index;
		            (\sum integer jj; 1 <= jj <= 2*count; ((ii*ii + jj*jj) <= center ? 1 : 0));
		    loop assigns index, result, i, diagnalLengthSquare;
		    loop variant 2*count - index + 1;
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			    loop invariant 1 <= i <= 2*count + 1;
			    loop invariant result ==
			        \sum integer ii; 1 <= ii < index;
			            (\sum integer jj; 1 <= jj <= 2*count; ((ii*ii + jj*jj) <= center ? 1 : 0))
			        + \sum integer jj; 1 <= jj < i; ((index*index + jj*jj) <= center ? 1 : 0);
			    loop assigns i, result, diagnalLengthSquare;
			    loop variant 2*count - i + 1;
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
