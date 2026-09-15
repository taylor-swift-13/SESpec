
/*@
  predicate prefix_nonzero{L}(int *x, integer n, integer i) =
    0 <= i <= n &&
    (\forall integer k; 0 <= k < i ==> x[k] != 0);
*/

int foo107(int * x, int x_len) {

         	assert(x_len >= 0);
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] != 0;
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre);
          loop assigns index;
            */
            while (x_len - index > 0 && x[index] != 0) {
                		index = index + 1;
            		}
            
            		if (x_len - index == 0) {
               			index = -1;
            		}
            	return index;
        	}
}
