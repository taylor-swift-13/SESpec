
/*@
*/

/*@
  requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires x_len > 0;
  requires x_len < 100;
  assigns \nothing;
  ensures (\result == -1) ==> (\forall integer k; 0 <= k < x_len ==> x[k] != 0);
  ensures (\result != -1) ==> (0 <= \result < x_len && x[\result] == 0
                               && (\forall integer k; 0 <= k < \result ==> x[k] != 0));
  ensures \result == (-1);
*/
int foo107(int * x, int x_len) {

         	assert(x_len >= 0);
         	if (x_len == 0) {
            		return -1;
        	} else {
            		int index = 0;

            		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index <= x_len;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] != 0;
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
