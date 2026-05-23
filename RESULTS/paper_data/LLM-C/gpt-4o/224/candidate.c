/*@
    requires \valid(args+(0..args_len-1));
    requires args_len >= array;
    requires array >= 0;
    ensures \result >= 1 && \result <= array;
    ensures \result == array ==> \forall integer i; 0 <= i < array ==> args[i] == i + 1;
    ensures \result < array ==> args[\result - 1] != \result;
    assigns \nothing;
*/
int findMissing(int * args, int args_len, int array);

int findMissing(int * args, int args_len, int array) {

		int found = 1;
		if (array == 0 || array == 1) {
			return found;
		}
		/*@
        loop invariant 1 <= num <= array + 1;
        loop invariant found >= 1 && found <= num;
        loop invariant \forall integer i; 1 <= i < num ==> (args[i - 1] == i ? found == i : found != i);
        loop assigns num, found;
        loop variant array - num;
        */
		for (int num = 1; num <= array; num++) {
			if (args[num - 1] == num) {
				found = num;
			} else if (args[num - 1] != num) {
				return num;
			}
		}
		return found;
}
