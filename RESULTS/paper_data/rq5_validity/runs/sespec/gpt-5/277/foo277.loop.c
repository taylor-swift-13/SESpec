
/*@
  requires arg_len >= 1;
  requires \valid_read(arg + (0 .. arg_len-1));
*/
int foo277(int * arg, int arg_len) {

		int g = 0;
		int ret = arg[0];
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= j <= arg_len;
          loop invariant \forall integer k; 0 <= k < j ==> ret <= arg[k];
          loop invariant \exists integer k0; 0 <= k0 < j && ret == arg[k0];
          loop invariant ret <= arg[0];
          loop invariant g >= 0;
          loop invariant (j < arg_len) ==> ((\forall integer k; 0 <= k < j ==> ret <= arg[k]) &&
                                            (\exists integer k0; 0 <= k0 < j && ret == arg[k0]));
          loop invariant (!(j < arg_len)) ==> (\forall integer k; 0 <= k < arg_len ==> ret <= arg[k]);
          loop invariant \forall integer k; 0 <= k < arg_len ==> arg[k] == \at(arg[k], Pre) ;
          loop assigns j, g, ret;
            */
            for (int j = 1; j < arg_len; j++) {
			if (arg[j] > ret) {
				g = g > ret ? g : ret;
			} else {
				ret = arg[j];
			}
		}
            
		return g;
}
