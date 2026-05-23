/*@
    requires args_len >= 0;
    requires num >= 0;
    requires num <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * args, int args_len, int num);

 /*@
    requires args_len >= 0;
    requires num >= 0;
    requires num <= args_len;
    requires \valid_read(args + (0 .. args_len - 1));
    assigns \nothing;
    ensures \result >= 0;
*/
int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop invariant \forall integer i; 0 <= i < index ==> \true;
		    loop assigns index, ret, c;
		    loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= c <= num;
			    loop invariant ret >= 0;
			    loop assigns c, ret;
			    loop variant num - c;
			*/
			for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
		}
		return ret;
}
