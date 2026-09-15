/*@
    requires array > 0;
    requires \valid(data + (0 .. array-1));
    assigns \nothing;
    ensures 0 <= \result < array;
    ensures (\result > 0) ==> data[\result-1] <= data[\result];
    ensures (\result < array-1) ==> data[\result] >= data[\result+1];
*/
int findPeak(int * data, int data_len, int array);

int findPeak(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		/*@
		    loop invariant 0 <= found <= top < array;
		    loop invariant \forall integer j; 0 <= j < found ==> data[j] < data[j+1];
		    loop assigns found, top;
		    loop variant top - found;
		*/
		while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}
