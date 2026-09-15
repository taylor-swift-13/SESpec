int findPeak(int * data, int data_len, int array);

/*@ 
  requires array >= 1;
  requires data_len >= array;
  requires \valid_read(data + (0 .. data_len-1));
  assigns \nothing;
  ensures 0 <= \result < array;
  ensures (\result > 0) ==> (data[\result] >= data[\result - 1]);
  ensures (\result < array - 1) ==> (data[\result] >= data[\result + 1]);
*/
int findPeak(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		/*@
		  loop invariant 0 <= i <= top < array;
		  loop invariant (i > 0) ==> (data[i] > data[i-1]);
		  loop invariant (top < array - 1) ==> (data[top] >= data[top+1]);
		  loop assigns i, top;
		  loop variant top - i;
		*/
		while (i < top) {
			int p = i + (top - i) / 2;
			/*@ assert i <= p < top; */
			/*@ assert 0 <= p < array - 1; */
			/*@ assert \valid_read(data + (p)) && \valid_read(data + (p+1)); */
			if (data[p] < data[p + 1]) {
				i = p + 1;
				/*@ assert (i > 0) ==> (data[i] > data[i-1]); */
			} else {
				top = p;
				/*@ assert (top < array - 1) ==> (data[top] >= data[top+1]); */
			}
		}
		/*@ assert i == top; */
		/*@ assert (i > 0) ==> (data[i] >= data[i-1]); */
		/*@ assert (i < array - 1) ==> (data[i] >= data[i+1]); */
		return i;
}
