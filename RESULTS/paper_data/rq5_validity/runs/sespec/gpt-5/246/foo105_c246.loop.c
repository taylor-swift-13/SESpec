
/*@
  logic integer invcount(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : invcount(a, lo, hi - 1)
               + (\sum(lo, hi - 1, \lambda integer k; (a[k] > a[hi - 1]) ? 1 : 0));
*/
        
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo105_c246(int * args, int args_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index <= num || index == 0;
          loop invariant num == \at(num,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant 0 <= ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= k;
          loop invariant k <= num;
          loop invariant 0 <= ret;
          loop assigns index, ret;
            */
            for (int k = index + 1; k < num; k++) {
				if (args[index] > args[k]) {
					ret++;
				}
			}
            
		}
            
		return ret;
}
