
/*@
  logic integer first_zero_or_end(int* x, integer lo, integer hi) =
    lo >= hi ? hi :
    (x[lo] == 0 ? lo : first_zero_or_end(x, lo + 1, hi));
*/

/*@ requires x_len >= 0;
    requires x_len == 0 || \valid_read(x + (0 .. x_len - 1));
    assigns \nothing;
    ensures x_len == 0 ==> \result == -1;
    ensures x_len > 0 ==> (-1 <= \result < x_len);
    ensures \result != -1 ==> 0 <= \result < x_len && x[\result] == 0;
    ensures \result != -1 ==> \forall integer k; 0 <= k < \result ==> x[k] != 0;
    ensures \result == -1 <==> \forall integer k; 0 <= k < x_len ==> x[k] != 0;
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
          loop invariant index <= x_len;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] != 0;
          loop invariant index == 0 || x[index - 1] != 0;
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre);
          loop invariant (x_len - index > 0 && x[index] != 0) ==> (index < x_len);
          loop invariant (!(x_len - index > 0 && x[index] != 0)) ==> (index == x_len || x[index] == 0);
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
