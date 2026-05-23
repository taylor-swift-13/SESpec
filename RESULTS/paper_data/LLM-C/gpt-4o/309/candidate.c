/*@ 
    requires \valid(positions + (0..positions_len-1));
    requires positions_len > 0;
    ensures \result >= 0;
    ensures \result == 0 ==> \forall integer i; 0 <= i < positions_len ==> positions[i] <= 0;
    ensures \result > 0 ==> \exists integer i; 0 <= i < positions_len && positions[i] == \result;
    ensures \result > 0 ==> \forall integer i; 0 <= i < positions_len && positions[i] > 0 ==> positions[i] <= \result;
    assigns \nothing;
*/
int largestPos(int * positions, int positions_len) {

		int largest = 0;
		/*@
		loop invariant 0 <= index <= positions_len;
		loop invariant largest >= 0;
		loop invariant \forall integer i; 0 <= i < index && positions[i] > 0 ==> positions[i] <= largest;
		loop invariant largest == 0 ==> \forall integer i; 0 <= i < index ==> positions[i] <= 0;
		loop assigns index, largest;
		loop variant positions_len - index;
		*/
		for (int index = 0; index < positions_len; index++) {
			if (positions[index] > 0 && positions[index] > largest) {
				largest = positions[index];
			}
		}
		return largest;
}
