/*@
    requires \valid(args + (0..array-1));
    requires args_len >= array;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && args[i] % 2 != 0 && \result == args[i]);
    assigns \nothing;
*/
int getOddOccurrence(int * args, int args_len, int array);

int getOddOccurrence(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= array;
		    loop invariant 0 <= start <= index;
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && args[i] % 2 != 0 && start % 2 != 0 && ret == args[i]);
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
