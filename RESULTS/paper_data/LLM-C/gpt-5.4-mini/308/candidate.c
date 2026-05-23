/*@ 
    requires positions_len >= 0;
    requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> \result >= positions[i];
    ensures \exists integer i; 0 <= i < positions_len && positions[i] > 0 ==> (\result == 0 || \result == positions[i]);
*/
int largestPos(int * positions, int positions_len);

 /*@ 
    requires positions_len >= 0;
    requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> \result >= positions[i];
    ensures \exists integer i; 0 <= i < positions_len && positions[i] > 0 ==> (\result == 0 || \result == positions[i]);
*/
int largestPos(int * positions, int positions_len) {

		int result = 0;
		/*@
		    loop invariant 0 <= index <= positions_len;
		    loop invariant result >= 0;
		    loop invariant \forall integer i; 0 <= i < index && positions[i] > 0 ==> result >= positions[i];
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
