/*@
    requires args_len >= 0;
    requires array >= 0;
    requires \valid_read(args + (0 .. array-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && args[i] % 2 != 0 && \result == args[i]);
*/
int getOddOccurrence(int * args, int args_len, int array);

 /*@
    requires args_len >= 0;
    requires array >= 0;
    requires \valid_read(args + (0 .. array-1));
    assigns \nothing;
    ensures \result == 0 || (\exists integer i; 0 <= i < array && args[i] % 2 != 0 && \result == args[i]);
*/
int getOddOccurrence(int * args, int args_len, int array) {

		int ret = 0;
		int start = 0;
		/*@
		    loop invariant 0 <= index <= array;
		    loop invariant start >= 0;
		    loop invariant ret == 0 || (\exists integer i; 0 <= i < index && args[i] % 2 != 0 && ret == args[i]);
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
