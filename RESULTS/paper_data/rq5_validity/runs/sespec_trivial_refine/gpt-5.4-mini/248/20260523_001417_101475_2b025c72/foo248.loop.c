
/*@
  logic integer count_gt(int *a, integer i, integer j) = \numof(integer k; i <= k < j && a[i] > a[k]);
*/

/*@ 
  requires 0 <= args_len;
  requires 0 <= num <= args_len;
  requires num == 0 || \valid_read(args + (0 .. num - 1));
*/

int foo248(int * args, int args_len, int num) {

		int ret = 0;

		/*@
		  loop invariant 0 <= index <= num;
		  loop invariant 0 <= ret;
		  loop assigns ret, index, c;
		*/
		for (int index = 0; index < num; index++) {
			
            /*@
          loop invariant index + 1 <= c <= num;
          loop invariant 0 <= ret;
          loop assigns ret, c;
            */
            for (int c = index + 1; c < num; c++) {
				if (args[index] > args[c]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
