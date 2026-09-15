/*@
    requires count > 0;
    ensures \result >= 0;
*/
int countRectangles(int count);

int countRectangles(int count) {

		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;

		/*@
		    loop invariant 1 <= index <= 2 * count + 1;
		    loop invariant result >= 0;
		    loop assigns index, result;
		    loop variant 2 * count - index + 1;
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			    loop invariant 1 <= i <= 2 * count + 1;
			    loop invariant result >= 0;
			    loop assigns i, result;
			    loop variant 2 * count - i + 1;
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
