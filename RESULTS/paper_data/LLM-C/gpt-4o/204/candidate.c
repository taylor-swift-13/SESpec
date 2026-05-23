/*@
    requires \valid(ints + (0..ints_len-1));
    requires array > 0;
    requires ints_len >= array;
    ensures \result >= 0;
    ensures \result <= array;
    assigns \nothing;
*/
int findMinSwaps(int * ints, int ints_len, int array);

int findMinSwaps(int * ints, int ints_len, int array) {

		int find = 0;
		int offset = 0;
		int max = 1;

		/*@
		loop invariant 0 <= offset <= array;
		loop invariant 1 <= max <= array;
		loop invariant 0 <= find <= array;
		loop invariant \forall integer i, j; 0 <= i < offset && 1 <= j < max ==> ints[i] != ints[j] || find > 0;
		loop assigns offset, max, find;
		loop variant array - offset;
		*/
		while (offset < array && max < array) {
			if (ints[offset] == ints[max]) {
				offset++;
				max++;
				find++;
			} else if (ints[offset] > ints[max]) {
				offset++;
			} else {
				max++;
			}
		}

		return find;
}
