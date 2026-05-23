
/*@ predicate same_prefix(int *a, int *b, integer n, integer i) =
      0 <= i <= n &&
      \forall integer k; 0 <= k < i ==> a[k] == b[k];
*/       

/*@
  requires a != \null && b != \null;
  requires a_len == b_len;
  requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len - 1));
  requires \valid_read(b + (0 .. b_len - 1));
*/
int foo12(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@
          loop invariant 0 <= i <= a_len;
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
