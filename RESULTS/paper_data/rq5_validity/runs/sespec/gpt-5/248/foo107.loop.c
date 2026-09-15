
/*@
  logic integer invcount(int* a, integer i, integer n) =
    i >= n ? 0 : invcount(a, i, n - 1) + (a[i] > a[n] ? 1 : 0);
*/

/*@
  logic integer total_invcount(int* a, integer n) =
    n <= 1 ? 0 : total_invcount(a, n - 1) + invcount(a, n - 1, n - 1);
*/

/*@
        predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
        */
        
/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
*/

int foo107(int * args, int args_len, int num) {

		int ret = 0;

		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index >= 0;
          loop invariant ret >= 0;
          loop invariant num == \at(num,Pre);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
          loop assigns index, ret;
            */
            for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c <= num;
          loop invariant 0 <= index <= num;
          loop invariant ret >= 0;
          loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k],Pre);
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
