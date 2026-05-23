/*@
    requires \valid(args+(0..args_len-1));
    requires 0 <= num <= args_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < num, \sum(i+1 <= j < num, args[i] > args[j]));
    assigns \nothing;
*/
int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@
        loop invariant 0 <= index <= num;
        loop invariant ret >= 0;
        loop assigns index, ret;
        */
		for (int index = 0; index < num; index++) {
			/*@
            loop invariant index + 1 <= k <= num;
            loop invariant ret >= 0;
            loop invariant \forall integer i, j; 0 <= i < index && i+1 <= j < num ==> args[i] > args[j] ==> ret >= 1;
            loop assigns k, ret;
            */
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
}
