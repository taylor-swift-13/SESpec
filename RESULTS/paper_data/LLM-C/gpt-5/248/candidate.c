int getInvCount(int * args, int args_len, int num);

/*@ 
  logic integer inv_pairs_upto{L}(int *a, integer i, integer n) =
    i <= 0 ? 0 :
      inv_pairs_upto{L}(a, i-1, n)
      + (\numof integer j; (i-1) < j < n && \at(a[i-1], L) > \at(a[j], L));
*/

/*@ 
  requires args_len >= 0;
  requires 0 <= num <= args_len;
  requires num == 0 || \valid_read(args + (0 .. num-1));
  assigns \nothing;
  ensures 0 <= \result <= (num * (num - 1)) / 2;
  ensures \result == inv_pairs_upto{Pre}(args, num, num);
  ensures (\forall integer i, j; 0 <= i < j < num ==> \at(args[i],Pre) <= \at(args[j],Pre)) ==> \result == 0;
  ensures (\forall integer i, j; 0 <= i < j < num ==> \at(args[i],Pre) > \at(args[j],Pre)) ==> \result == (num * (num - 1)) / 2;
*/
int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@ 
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
		  loop invariant ret == inv_pairs_upto{Pre}(args, index, num);
		  loop assigns index, ret;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@ 
			  loop invariant index + 1 <= c <= num;
			  loop invariant 0 <= ret <= (num * (num - 1)) / 2;
			  loop invariant ret == inv_pairs_upto{Pre}(args, index, num)
			                    + (\numof integer j; index < j < c && \at(args[index],Pre) > \at(args[j],Pre));
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
