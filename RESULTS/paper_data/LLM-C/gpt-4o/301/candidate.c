/*@
    requires \valid(data + (0..data_len-1));
    requires data_len > 0;
    requires array > 0 && array <= data_len;
    ensures 0 <= \result < array;
    ensures \forall integer i; 0 <= i < \result ==> data[i] <= data[\result];
    ensures \forall integer i; \result < i < array ==> data[i] <= data[\result];
    assigns \nothing;
*/
int findPeak(int * data, int data_len, int array);

int findPeak(int * data, int data_len, int array) {

		int found = 0, top = array - 1;
		/*@
		    loop invariant 0 <= found <= top < array;
		    loop invariant \forall integer i; 0 <= i < found ==> data[i] <= data[found];
		    loop invariant \forall integer i; top < i < array ==> data[i] <= data[top];
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
