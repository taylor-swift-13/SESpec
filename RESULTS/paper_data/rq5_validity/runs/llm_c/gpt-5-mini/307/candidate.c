/*@
    requires positions_len >= 0;
    requires positions_len == 0 || \valid(positions + (0 .. positions_len-1));
    assigns \nothing;
    ensures \result >= 0;
    /* If no positive elements, result is 0 */
    ensures (\forall integer i; 0 <= i < positions_len ==> positions[i] <= 0) ==> \result == 0;
    /* If there is at least one positive element, result is the maximum of positive elements */
    ensures (\exists integer i; 0 <= i < positions_len && positions[i] > 0) ==>
            (\result > 0
             && (\forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> positions[i] <= \result)
             && (\exists integer i; 0 <= i < positions_len && positions[i] == \result));
*/
int largestPos(int * positions, int positions_len);

int largestPos(int * positions, int positions_len) {

		int largest = 0;
		/*@
		    loop invariant 0 <= count <= positions_len;
		    loop invariant largest >= 0;
		    /* All examined elements are <= largest */
		    loop invariant \forall integer j; 0 <= j < count ==> positions[j] <= largest;
		    /* If largest > 0 then it is equal to some examined element */
		    loop invariant largest > 0 ==> (\exists integer j; 0 <= j < count && positions[j] == largest);
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
