int getOddOccurrence(int * array, int array_len, int Array);

int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		loop invariant 0 <= index <= Array;
		loop invariant 0 <= start <= index;
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret);
		loop invariant start == (\num_of integer k; 0 <= k < index && array[k] % 2 != 0);
		loop assigns index;
		loop assigns start;
		loop assigns ret;
		*/
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}
