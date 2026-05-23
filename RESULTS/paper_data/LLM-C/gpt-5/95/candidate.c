int arrcmp(int * a, int a_len, int * b, int b_len);

/*@ 
  requires a_len >= 0 && b_len >= 0;
  assigns \nothing;

  behavior diff_len:
    assumes a_len != b_len;
    ensures \result == 0;

  behavior same_len:
    assumes a_len == b_len;
    requires \valid_read(a + (0 .. a_len - 1)) && \valid_read(b + (0 .. b_len - 1));
    ensures (\result == 1) <==> (\forall integer i; 0 <= i < a_len ==> a[i] == b[i]);

  ensures \result == 0 || \result == 1;

  complete behaviors diff_len, same_len;
  disjoint behaviors diff_len, same_len;
*/
int arrcmp(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@ assert \valid_read(a + (0 .. a_len - 1)) && \valid_read(b + (0 .. b_len - 1)); */

        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
          loop assigns i;
          loop variant a_len - i;
        */
        for(int i = 0; i < a_len; i++) {
            if(a[i] != b[i]) {
                return 0;
            }
        }

        return 1;
}
