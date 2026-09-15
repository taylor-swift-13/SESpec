int getInvCount(int * args, int args_len, int num);

/*@ 
  requires args != \null;
  requires args_len >= 0;
  requires 0 <= num <= args_len;
  requires \valid_read(args + (0 .. args_len-1));

  assigns \nothing;

  ensures \result ==
           \sum(integer i=0 .. num-1,
                \sum(integer j=i+1 .. num-1, args[i] > args[j] ? 1 : 0));

  ensures 0 <= \result <= (num * (num - 1)) / 2;
*/
int getInvCount(int * args, int args_len, int num) {

		int ret = 0;

		/*@
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret <= index*num - index*(index+1)/2;
		  loop invariant ret ==
		    \sum(integer i=0 .. index-1,
		         \sum(integer j=i+1 .. num-1, args[i] > args[j] ? 1 : 0));
		  loop assigns index, ret;
		  loop variant num - index;
		*/
		for (int index = 0; index < num; index++) {
			/*@
			  loop invariant index + 1 <= k <= num;
			  loop invariant ret ==
			    \sum(integer i=0 .. index-1,
			         \sum(integer j=i+1 .. num-1, args[i] > args[j] ? 1 : 0))
			    + \sum(integer j=index+1 .. k-1, args[index] > args[j] ? 1 : 0);
			  loop assigns k, ret;
			  loop variant num - k;
			*/
			for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
		}
		return ret;
}
