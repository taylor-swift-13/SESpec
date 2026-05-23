/*@
    requires \valid(args+(0..args_len-1));
    requires 0 <= num <= args_len;
    ensures \result >= 0;
    ensures \result == \sum(0 <= i < num, \sum(i+1 <= j < num, args[i] > args[j] ? 1 : 0));
    assigns \nothing;
*/
int getInvCount(int * args, int args_len, int num);

int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@
		    loop invariant 0 <= index <= num;
		    loop invariant ret >= 0;
		    loop assigns index, ret;
		    loop invariant \forall integer i; 0 <= i < index ==> 
		        \forall integer j; i+1 <= j < num ==> 
		        (args[i] > args[j] ? ret >= \sum(0 <= k < i, \sum(k+1 <= l < num, args[k] > args[l] ? 1 : 0)) : \true);
		*/
		for (int index = 0; index < num; index++) {
			/*@
			    loop invariant index + 1 <= c <= num;
			    loop invariant ret >= 0;
			    loop assigns c, ret;
			    loop invariant \forall integer i; 0 <= i < index ==> 
			        \forall integer j; i+1 <= j < num ==> 
			        (args[i] > args[j] ? ret >= \sum(0 <= k < i, \sum(k+1 <= l < num, args[k] > args[l] ? 1 : 0)) : \true);
			*/
			for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
		}
		return ret;
}
