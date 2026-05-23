
/*@
  // Helper: number of k in 1..m such that j*j + k*k <= center
  logic integer count_row_prefix(integer j, integer m, integer center) =
    m <= 0 ? 0 :
    ((j*j + m*m <= center) ? 1 + count_row_prefix(j, m - 1, center) : count_row_prefix(j, m - 1, center));
  
  // Number of k in 1..(2*cnt) such that j*j + k*k <= center
  logic integer count_row(integer j, integer cnt, integer center) =
    count_row_prefix(j, 2 * cnt, center);

  // Total number of pairs (j,k) with 1 <= j <= m, 1 <= k <= 2*cnt, and j*j + k*k <= center
  logic integer pairs_leq(integer m, integer cnt, integer center) =
    m <= 0 ? 0 : pairs_leq(m - 1, cnt, center) + count_row(m, cnt, center);
*/

/*@
  requires count >= 0;
  assigns \nothing;
  ensures \result == pairs_leq(2 * count, count, (2 * count) * (2 * count));
  ensures 0 <= \result;
  ensures count == \old(count);
  ensures count == 0 ==> \result == 0;
*/
int foo311(int count) {

	int result = 0;
	int diameter = 2 * count;
	int center = diameter * diameter;
	
	/*@
	  loop invariant 1 <= index && index <= 2 * count + 1;
	  loop invariant 0 <= result;
	  loop invariant center == (2 * count) * (2 * count);
	  loop invariant diameter == 2 * count;
	  loop invariant result == pairs_leq(index - 1, count, center);
	  loop assigns index, result;
	*/
	for (int index = 1; index <= 2 * count; index++) {
		
		/*@
		  loop invariant 1 <= i && i <= 2 * count + 1;
		  loop invariant 0 <= result;
		  loop invariant center == (2 * count) * (2 * count);
		  loop invariant diameter == 2 * count;
		  loop invariant result == pairs_leq(index - 1, count, center) + count_row_prefix(index, i - 1, center);
		  loop assigns i, result;
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
