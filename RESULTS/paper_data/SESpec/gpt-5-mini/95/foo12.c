
/*@ predicate same_prefix(int *a, int *b, integer n, integer i) =
      0 <= i <= n &&
      \forall integer k; 0 <= k < i ==> a[k] == b[k];
*/       

/*@
  requires a_len == b_len;
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len-1));
  requires \valid(b + (0 .. b_len-1));
  assigns \nothing;
  ensures (a_len != b_len) ==> \result == 0;
  ensures (a_len == b_len) ==> (\result == 1 <==> (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]));
  ensures (a_len == b_len) ==> (\result == 0 <==> (\exists integer k; 0 <= k < a_len && a[k] != b[k]));
*/
int foo12(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
          loop invariant i < a_len ==> \valid(a + i) && \valid(b + i);
          loop assigns i;
        */
        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
