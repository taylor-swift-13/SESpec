
/* No additional predicates or logic functions are needed. */

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures args_len == \at(args_len,Pre);
  ensures args == \at(args,Pre);
  ensures \forall integer k; 0 <= k < \at(args_len,Pre) ==> args[k] == \at(args[k],Pre);
*/
int foo279(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (j < \at(args_len,Pre)) ==> (\forall integer k; 0 <= k < \at(args_len,Pre) ==> \at(args[k],Pre) == args[k]);
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> \at(args[k],Pre) == args[k] ;
          loop assigns j, g, ret;
            */
            for (int j = 1; j < args_len; j++) {
			if (args[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = args[j];
			}
		}
            
		return g;
}
