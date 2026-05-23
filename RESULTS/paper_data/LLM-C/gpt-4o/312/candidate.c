/*@
    requires count > 0;
    ensures \result >= 0;
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;

		/*@
		    loop invariant 1 <= i <= 2 * count + 1;
		    loop invariant ret >= 0;
		    loop assigns i, ret;
		    loop variant 2 * count - i + 1;
		*/
		for (int i = 1; i <= 2 * count; i++) {
			/*@
			    loop invariant 1 <= c <= 2 * count + 1;
			    loop invariant ret >= 0;
			    loop assigns c, ret;
			    loop variant 2 * count - c + 1;
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
