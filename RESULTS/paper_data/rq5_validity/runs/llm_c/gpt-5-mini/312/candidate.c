int countRectangles(int count);

/*@
    requires count >= 0;
    assigns \nothing;
    ensures 0 <= \result;
    ensures \result <= 4 * count * count;
    ensures \result == \sum integer i; 1 <= i <= 2*count;
                        (\sum integer c; 1 <= c <= 2*count;
                            ((i*i + c*c <= 4*count*count) ? 1 : 0));
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		    loop invariant 1 <= i <= 2*count + 1;
		    loop invariant ret == \sum integer ii; 1 <= ii < i;
		                        (\sum integer cc; 1 <= cc <= 2*count;
		                            ((ii*ii + cc*cc <= center) ? 1 : 0));
		    loop assigns i, ret;
		    loop variant 2*count - i + 1;
		*/
		for (int i = 1; i <= 2 * count; i++) {
			/*@
			    loop invariant 1 <= c <= 2*count + 1;
			    loop invariant ret == \sum integer ii; 1 <= ii < i;
			                        (\sum integer cc; 1 <= cc <= 2*count;
			                            ((ii*ii + cc*cc <= center) ? 1 : 0))
			                     + \sum integer cc; 1 <= cc < c;
			                            ((i*i + cc*cc <= center) ? 1 : 0);
			    loop assigns c, ret;
			    loop variant 2*count - c + 1;
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
