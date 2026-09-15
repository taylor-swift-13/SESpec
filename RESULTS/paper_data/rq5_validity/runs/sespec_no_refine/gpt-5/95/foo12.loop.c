
/*@ 
  logic integer count_eq_seg{L}(int* a, int* b, integer lo, integer hi) =
    lo >= hi ? 0
             : count_eq_seg(a, b, lo, hi - 1) + (a[hi - 1] == b[hi - 1] ? 1 : 0);
*/

/*@ 
  requires a_len >= 0 && b_len >= 0;
  requires \valid_read(a + (0 .. a_len-1));
  requires \valid_read(b + (0 .. b_len-1));
  ensures \result == 1 ==> a_len == b_len && (\forall integer k; 0 <= k < a_len ==> a[k] == b[k]);
  ensures \result == 0 ==> (a_len != b_len) || (\exists integer k; 0 <= k < a_len && 0 <= k < b_len && a[k] != b[k]);
*/
int foo12(int * a, int a_len, int * b, int b_len) {

        if(a_len != b_len) {
	    return 0;
        }

        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
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
