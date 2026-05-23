/*@
    requires \valid(data+(0..data_len-1));
    requires data_len > 0;
    requires array > 0;
    ensures 0 <= \result < data_len;
    ensures \forall integer k; 0 <= k < \result ==> data[k] <= data[\result];
    ensures \forall integer k; \result < k < data_len ==> data[k] <= data[\result];
    assigns \nothing;
*/
int findPeak(int * data, int data_len, int array);

int findPeak(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		/*@
        loop invariant 0 <= i <= top < array;
        loop invariant \forall integer k; 0 <= k < i ==> data[k] <= data[i];
        loop invariant \forall integer k; top < k < array ==> data[k] <= data[top];
        loop assigns i, top;
        loop variant top - i;
        */
		while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
		return i;
}
