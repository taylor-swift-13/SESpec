int getPairsCount(int * array, int array_len, int num, int p);

/*@
    requires num >= 0;
    requires array_len >= 0;
    requires num <= array_len;
    requires \forall integer i; 0 <= i < num ==> \valid_read(array + i);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \num_of integer i,j; 0 <= i < j < num && array[i] + array[j] == p;
*/
int getPairsCount(int * array, int array_len, int num, int p) {

		int ret = 0;
		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop invariant ret == \num_of integer i,j; 0 <= i < j < index && array[i] + array[j] == p;
		    loop assigns index, ret;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index < num;
			    loop invariant index + 1 <= j <= num;
			    loop invariant ret == \num_of integer i,j2; 0 <= i < j2 < index && array[i] + array[j2] == p
			                      + \num_of integer k; index < k < j && array[index] + array[k] == p;
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
