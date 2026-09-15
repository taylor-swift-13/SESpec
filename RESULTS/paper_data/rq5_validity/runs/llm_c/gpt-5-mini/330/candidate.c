int difference(int diff);

 /*@
     requires diff >= 0;
     assigns \nothing;
     ensures \result == \sum integer j; 1 <= j <= diff; (j*j*j - j);
 */
int difference(int diff) {

		int result = 0;
		int max = 0;
		/*@
		    loop invariant 1 <= j <= diff+1;
		    loop invariant result == \sum integer k; 1 <= k < j; k*k*k;
		    loop assigns j, result;
		    loop variant diff - j + 1;
		*/
		for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
		/*@
		    loop invariant 1 <= j <= diff+1;
		    loop invariant max == \sum integer k; 1 <= k < j; k;
		    loop assigns j, max;
		    loop variant diff - j + 1;
		*/
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
}
