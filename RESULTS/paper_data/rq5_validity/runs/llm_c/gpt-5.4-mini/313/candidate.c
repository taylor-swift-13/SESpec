/*@
    requires count >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int countRectangles(int count);

 /*@
    requires count >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		    loop invariant 1 <= index <= 2 * count + 1;
		    loop invariant 0 <= ret <= (index - 1) * (2 * count);
		    loop assigns index, ret, i;
		    loop variant 2 * count - index + 1;
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			    loop invariant 1 <= i <= 2 * count + 1;
			    loop invariant 0 <= ret <= index * (i - 1) + (index - 1) * (2 * count - (i - 1));
			    loop assigns i, ret;
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
