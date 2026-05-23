
/*@
predicate arrays_equal{L}(int *a, int *b, integer n) =
  \forall integer k; 0 <= k < n ==> a[k] == b[k];
*/

int foo95(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
          loop assigns i;
            */
            for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }
            

        return 1;
}
