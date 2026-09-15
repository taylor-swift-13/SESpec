int countRectangles(int count);

/*@ 
  requires 0 <= count <= 16383;
  assigns \nothing;
  ensures \result ==
    \sum(integer x, 1, 2*count,
      \sum(integer y, 1, 2*count,
        ((x*x + y*y <= (2*count)*(2*count)) ? 1 : 0)));
  ensures 0 <= \result <= (2*count)*(2*count);
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@
		  loop invariant 1 <= index <= 2*count + 1;
		  loop invariant ret ==
		    \sum(integer x, 1, index-1,
		      \sum(integer y, 1, 2*count,
		        (((x*x + y*y) <= center) ? 1 : 0)));
		  loop assigns index, ret;
		  loop variant (2*count + 1 - index);
		*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			  loop invariant 1 <= i <= 2*count + 1;
			  loop invariant ret ==
			    \at(ret,LoopEntry) +
			    \sum(integer y, 1, i-1,
			      (((index*index + y*y) <= center) ? 1 : 0));
			  loop assigns i, ret;
			  loop variant (2*count + 1 - i);
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
