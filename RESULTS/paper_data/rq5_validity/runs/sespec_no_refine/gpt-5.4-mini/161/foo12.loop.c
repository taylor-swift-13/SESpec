
/*@
  logic integer array_eq_prefix(int *a, int *b, integer n) =
    n <= 0 ? 1 :
      array_eq_prefix(a, b, n - 1) &&
      a[n - 1] == b[n - 1];
*/

int foo12(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        
            
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant array_eq_prefix(a, b, i);
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer k; 0 <= k < b_len ==> b[k] == \at(b[k], Pre);
          loop assigns i;
        */
            for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }
            

        return 1;
}
