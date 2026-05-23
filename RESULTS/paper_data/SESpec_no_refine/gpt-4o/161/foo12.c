
/*@
  logic integer array_equal(int* a, int* b, integer len) =
    len <= 0 ? 1 : (a[len - 1] == b[len - 1] && array_equal(a, b, len - 1));
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires \valid(b + (0..b_len-1));
  requires a_len >= 0 && b_len >= 0;
  assigns \nothing;
  ensures \result == 1 <==> (a_len == b_len && array_equal(a, b, a_len));
  ensures \result == 0 <==> (a_len != b_len || !array_equal(a, b, a_len));
*/
int foo12(int * a, int a_len, int * b, int b_len) {

    if(a_len != b_len) {
        return 0;
    }

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
      loop invariant \forall integer k; 0 <= k < b_len ==> b[k] == \at(b[k], Pre);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
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
