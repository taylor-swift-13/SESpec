/*@
    requires count > 0;
    ensures \result >= 0;
    ensures \result == \sum(1 <= index <= 2 * count, \sum(1 <= i <= 2 * count, ((index * index + i * i) <= (2 * count) * (2 * count) ? 1 : 0)));
    assigns \nothing;
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;

		/*@
		loop invariant 1 <= index <= 2 * count + 1;
		loop invariant ret >= 0;
		loop invariant ret == \sum(1 <= j < index, \sum(1 <= i <= 2 * count, ((j * j + i * i) <= center ? 1 : 0)));
		loop assigns index, ret;
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			loop invariant 1 <= i <= 2 * count + 1;
			loop invariant ret >= 0;
			loop invariant ret == \sum(1 <= j < index, \sum(1 <= k <= 2 * count, ((j * j + k * k) <= center ? 1 : 0)))
			                     + \sum(1 <= k < i, ((index * index + k * k) <= center ? 1 : 0));
			loop assigns i, ret;
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
