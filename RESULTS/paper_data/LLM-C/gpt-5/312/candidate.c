int countRectangles(int count);

/*@ 
  logic integer indicator(integer i, integer c, integer M) = 
    ((1 <= i && i <= M && 1 <= c && c <= M && i*i + c*c <= M*M) ? 1 : 0);

  logic integer count_pairs(integer M) = 
    (\sum(integer ii = 1 .. M) ( \sum(integer cc = 1 .. M) indicator(ii, cc, M) ));

  requires 0 <= count <= 16383;
  assigns \nothing;
  ensures \result == count_pairs(2*count);
  ensures 0 <= \result <= (2*count) * (2*count);
  ensures count == 0 ==> \result == 0;
*/
int countRectangles(int count) {

		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@ 
		  loop invariant 1 <= i <= 2*count + 1;
		  loop invariant 0 <= ret <= (i-1) * (2*count);
		  loop invariant ret == (\sum(integer ii = 1 .. i-1) ( \sum(integer cc = 1 .. 2*count) indicator(ii, cc, 2*count) ));
		  loop assigns i, ret;
		  loop variant (2*count + 1 - i);
		*/
		for (int i = 1; i <= 2 * count; i++) {
			/*@ 
			  loop invariant 1 <= c <= 2*count + 1;
			  loop invariant ret == (\sum(integer ii = 1 .. i-1) ( \sum(integer cc = 1 .. 2*count) indicator(ii, cc, 2*count) ))
			                      + (\sum(integer cc = 1 .. c-1) indicator(i, cc, 2*count));
			  loop invariant 0 <= ret - (\sum(integer ii = 1 .. i-1) ( \sum(integer cc = 1 .. 2*count) indicator(ii, cc, 2*count) )) <= c-1;
			  loop assigns c, ret;
			  loop variant (2*count + 1 - c);
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
