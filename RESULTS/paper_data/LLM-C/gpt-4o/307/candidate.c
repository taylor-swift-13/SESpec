/*@ 
    requires \valid(positions + (0..positions_len-1));
    requires positions_len > 0;
    ensures \result >= 0;
    ensures \result == 0 ==> \forall integer i; 0 <= i < positions_len ==> positions[i] <= 0;
    ensures \result > 0 ==> \exists integer i; 0 <= i < positions_len && positions[i] == \result;
    ensures \result > 0 ==> \forall integer i; 0 <= i < positions_len ==> positions[i] <= \result;
    assigns \nothing;
*/
int largestPos(int * positions, int positions_len);

int largestPos(int * positions, int positions_len) {

		int largest = 0;
		/*@
		loop invariant 0 <= count <= positions_len;
		loop invariant largest >= 0;
		loop invariant \forall integer i; 0 <= i < count ==> (positions[i] > 0 ==> positions[i] <= largest);
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
