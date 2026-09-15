/*@ 
    requires \valid(array + (0..array_len-1));
    requires 0 <= num <= array_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < num, \sum(i+1 <= j < num, (array[i] + array[j] == p ? 1 : 0)));
    assigns \nothing;
*/
int getPairsCount(int * array, int array_len, int num, int p);

int getPairsCount(int * array, int array_len, int num, int p) {

		int ret = 0;
		/*@
		loop invariant 0 <= index <= num;
		loop invariant ret == \sum(0 <= i < index, \sum(i+1 <= j < num, (array[i] + array[j] == p ? 1 : 0)));
		loop assigns index, ret;
		loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			loop invariant index + 1 <= j <= num;
			loop invariant ret == \sum(0 <= i < index, \sum(i+1 <= j < num, (array[i] + array[j] == p ? 1 : 0)))
			                     + \sum(index+1 <= k < j, (array[index] + array[k] == p ? 1 : 0));
			loop assigns j, ret;
			loop variant num - j;
			*/
			for (int j = index + 1; j < num; j++) {
				if (array[index] + array[j] == p) {
					ret++;
				}
			}
		}
		return ret;
}
