int getOddOccurrence(int * array, int array_len, int Array);

int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		loop invariant start == \numof{integer k; 0 <= k < index && array[k] % 2 != 0};
		loop invariant start == \numof(integer k, 0, index-1, array[k] % 2 != 0);
		loop invariant start == (\num_of integer k; 0 <= k < index && array[k] % 2 != 0);
		loop invariant start <= index;
		loop invariant start % 2 == 0 || start % 2 == 1;
		loop invariant ret == 0 || ret == array[start-1];
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret && array[k] % 2 != 0);
		loop invariant index <= Array;
		loop invariant \forall integer k; 0 <= k < index && array[k] % 2 != 0 ==> (k < start || ret == array[k]);
		loop invariant 0 <= start;
		loop invariant 0 <= index;
		loop assigns start;
		loop assigns ret;
		loop assigns index;
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
