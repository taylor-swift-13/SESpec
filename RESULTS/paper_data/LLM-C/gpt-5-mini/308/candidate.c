int largestPos(int * positions, int positions_len);

 /*@
     requires positions_len >= 0;
     requires positions_len == 0 || \valid(positions + (0 .. positions_len-1));
     assigns \nothing;
     ensures \result >= 0;
     ensures (\forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> positions[i] <= \result);
     ensures (\forall integer i; 0 <= i < positions_len ==> positions[i] <= \result || positions[i] <= 0);
     ensures (\forall integer i; 0 <= i < positions_len ==> positions[i] <= 0) ==> \result == 0;
     ensures (\exists integer i; 0 <= i < positions_len && positions[i] > 0) ==> (\exists integer i; 0 <= i < positions_len && positions[i] == \result);
 */
int largestPos(int * positions, int positions_len) {

		int result = 0;
		/*@
		    loop invariant 0 <= index <= positions_len;
		    loop invariant result >= 0;
		    loop invariant (\forall integer j; 0 <= j < index ==> positions[j] <= result);
		    loop invariant (\forall integer j; 0 <= j < index ==> positions[j] <= 0) ==> result == 0;
		    loop assigns index, result;
		    loop variant positions_len - index;
		*/
		for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > result) {
				result = positions[index];
			}
		}
		return result;
}
