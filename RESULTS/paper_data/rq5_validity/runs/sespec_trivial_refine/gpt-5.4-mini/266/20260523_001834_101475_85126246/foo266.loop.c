
/*@
predicate is_odd(integer x) = x % 2 != 0;
*/

int foo266(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		
        /*@
          loop invariant 0 <= index <= Array;
          loop invariant 0 <= start <= index;
          loop invariant start == \numof(int k, 0 <= k < index && array[k] % 2 != 0);
          loop invariant ret == 0 || ret % 2 != 0;
          loop assigns index, start, ret;
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
