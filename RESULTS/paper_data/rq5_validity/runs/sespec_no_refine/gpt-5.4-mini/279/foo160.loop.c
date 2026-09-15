
/*@
*/
int foo160(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= \at(args_len,Pre);
          loop invariant g == 0;
          loop invariant ret <= args[0];
          loop invariant (j < \at(args_len,Pre)) ==> (g == 0);
          loop invariant (j < \at(args_len,Pre)) ==> (((ret == args[0])&&(g == 0)&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (ret <= args[0]));
          loop invariant (!(j < \at(args_len,Pre))) ==> ((ret == args[0])&&(g == 0)&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer k; 0 <= k < \at(args_len,Pre) ==> args[k] == \at(args[k],Pre);
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
