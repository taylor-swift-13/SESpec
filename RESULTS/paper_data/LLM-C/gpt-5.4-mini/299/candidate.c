/*@
    requires \valid_read(data + (0 .. data_len - 1));
    requires data_len > 0;
    requires 0 < array <= data_len;
    assigns \nothing;
    ensures 0 <= \result < array;
    ensures \forall integer j; 0 <= j < \result ==> data[j] < data[j + 1];
    ensures \forall integer j; \result <= j < array - 1 ==> data[j] >= data[j + 1];
*/
int findPeak(int * data, int data_len, int array);

 /*@
    requires \valid_read(data + (0 .. data_len - 1));
    requires data_len > 0;
    requires 0 < array <= data_len;
    assigns \nothing;
    ensures 0 <= \result < array;
    ensures \forall integer j; 0 <= j < \result ==> data[j] < data[j + 1];
    ensures \forall integer j; \result <= j < array - 1 ==> data[j] >= data[j + 1];
*/
int findPeak(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		/*@
		    loop invariant 0 <= i <= top + 1;
		    loop invariant top < array;
		    loop invariant 0 <= top < array;
		    loop invariant \forall integer j; 0 <= j < i ==> data[j] < data[j + 1];
		    loop invariant \forall integer j; top <= j < array - 1 ==> data[j] >= data[j + 1];
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
