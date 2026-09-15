
/*@
  logic integer max_slice(int* a, integer lo, integer hi) =
    lo >= hi ? -2147483648
             : ( max_slice(a, lo, hi-1) > a[hi-1] ? max_slice(a, lo, hi-1) : a[hi-1] );
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires \valid_read(args + (0 .. \at(args_len,Pre)-1));
           assigns \nothing;   
  ensures args_len == \at(args_len,Pre) && args == \at(args,Pre);
  ensures \forall integer t; 0 <= t < args_len ==> args[t] == \at(args[t],Pre) ;
*/
int foo279(int * args, int args_len) {

		int g = 0;
		int ret = args[0];
		
            
        /*@
          loop invariant 1 <= j <= args_len;
          loop invariant (j < \at(args_len,Pre)) ==> (\exists integer k; 0 <= k < j && ret == args[k]);
          loop invariant (j < \at(args_len,Pre)) ==> (((ret == args[0])&&(g == 0)&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre))) || (\exists integer k; 0 <= k < j && ret == args[k]));
          loop invariant args_len == \at(args_len,Pre);
          loop invariant args == \at(args,Pre);
          loop invariant \forall integer t; 0 <= t < args_len ==> args[t] == \at(args[t],Pre) ;
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
