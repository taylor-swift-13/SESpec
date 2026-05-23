/*@
    requires \valid(array + (0..array_len-1));
    requires array_len > 0;
    requires Array == array_len;
    ensures 0 <= \result < array_len;
    ensures \forall integer i; 0 <= i < \result ==> array[i] <= array[\result];
    ensures \forall integer i; \result < i < array_len ==> array[i] <= array[\result];
    assigns \nothing;
*/
int findPeak(int * array, int array_len, int Array) {

		int found = 0, top = Array - 1;
		/*@
        loop invariant 0 <= found <= top < array_len;
        loop invariant \forall integer i; 0 <= i < found ==> array[i] <= array[found];
        loop invariant \forall integer i; top < i < array_len ==> array[i] <= array[top];
        loop assigns found, top;
        loop variant top - found;
        */
		while (found < top) {
			int i = found + (top - found) / 2;
			if (array[i] < array[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
