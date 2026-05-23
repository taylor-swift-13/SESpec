int getOddOccurrence(int * args, int args_len, int array);

/*@
    requires array >= 0;
    requires array == 0 || \valid_read(args + (0 .. array-1));
    assigns \nothing;
    ensures (\forall integer i; 0 <= i < array ==> args[i] % 2 == 0) ==> \result == 0;
    ensures (\exists integer i; 0 <= i < array && args[i] % 2 != 0) ==> (\exists integer k; 0 <= k < array && args[k] % 2 != 0 && \result == args[k]);
*/
int getOddOccurrence(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		/*@ 
		    loop invariant 0 <= index <= array;
		    loop invariant start >= 0 && start <= index;
		    loop invariant start == \sum integer k; 0 <= k < index; ((args[k] % 2) != 0 ? 1 : 0);
		    loop invariant ret == 0 || (\exists integer j; 0 <= j < index && args[j] % 2 != 0 && ret == args[j]);
		    loop assigns index, start, ret;
		    loop variant array - index;
		*/
		for (int index = 0; index < array; index++) {
			if (args[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = args[index];
				}
			}
		}
		return ret;
}
