int getOddOccurrence(int * array, int array_len, int Array);

/* 2. FUNC CONTRACT */
int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/* 1. LOOP INVARIANT */
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
