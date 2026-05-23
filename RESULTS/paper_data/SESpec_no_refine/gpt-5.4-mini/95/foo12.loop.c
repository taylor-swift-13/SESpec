
/*@ 
  predicate arrays_equal{L}(int *a, int *b, integer n) =
    \forall integer k; 0 <= k < n ==> a[k] == b[k];
*/

int foo12(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        
            
        /*@
          loop invariant \forall integer k; i <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer k; i <= k < b_len ==> b[k] == \at(b[k], Pre);
          loop assigns i;
            */
            for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }
            

        return 1;
}
