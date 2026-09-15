/*@
    requires positions_len >= 0;
    requires positions_len == 0 || \valid_read(positions + (0 .. positions_len - 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> \result >= positions[i];
    ensures (\exists integer i; 0 <= i < positions_len && positions[i] > 0) ==> \exists integer j; 0 <= j < positions_len && positions[j] > 0 && \result == positions[j];
    ensures (\forall integer i; 0 <= i < positions_len ==> positions[i] <= 0) ==> \result == 0;
*/
int largestPos(int * positions, int positions_len) {

		int largest = 0;
		/*@
		    loop invariant 0 <= count <= positions_len;
		    loop invariant largest >= 0;
		    loop invariant \forall integer i; 0 <= i < count && positions[i] > 0 ==> largest >= positions[i];
		    loop invariant (\exists integer i; 0 <= i < count && positions[i] > 0) ==> \exists integer j; 0 <= j < count && positions[j] > 0 && largest == positions[j];
		    loop assigns count, largest;
		    loop variant positions_len - count;
		*/
		for (int count = 0; count < positions_len; count++) {
			if (positions[count] > 0 && positions[count] > largest) {
				largest = positions[count];
			}
		}
		return largest;
}
