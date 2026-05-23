/*@
    requires 0 <= count <= 16383;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (2*count) * (2*count);
    ensures \result == \num_of integer i,j; 1 <= i <= 2*count && 1 <= j <= 2*count && (i * i + j * j) <= (2*count) * (2*count);
*/
int countRectangles(int count);

int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		    loop invariant 1 <= index <= 2*count + 1;
		    loop invariant ret >= 0;
		    loop invariant ret <= (2*count) * (2*count);
		    loop assigns index, ret;
		    loop variant 2*count - index + 1;
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			    loop invariant 1 <= i <= 2*count + 1;
			    loop invariant ret >= 0;
			    loop invariant ret <= (2*count) * (2*count);
			    loop assigns i, ret;
			    loop variant 2*count - i + 1;
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
