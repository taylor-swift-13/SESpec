int findPeak(int * data, int data_len, int array);

 /*@
     requires array > 0;
     requires \valid(data + (0 .. array-1));
     assigns \nothing;
     ensures 0 <= \result < array;
     ensures (\result == 0 || data[\result] >= data[\result-1]) &&
             (\result == array-1 || data[\result] >= data[\result+1]);
 */
int findPeak(int * data, int data_len, int array) {

		int i = 0, top = array - 1;
		/*@
		    loop invariant 0 <= i <= top;
		    loop invariant 0 <= top < array;
		    loop invariant \exists integer k; i <= k <= top &&
		                   ((k == 0 || data[k] >= data[k-1]) && (k == array-1 || data[k] >= data[k+1]));
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
