
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer array_sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : array_sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  predicate arrays_equal(int* a, int* b, integer len) =
    \forall integer i; 0 <= i < len ==> a[i] == b[i];
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires \valid(&b[0] + (0..b_len-1));
  requires \forall integer i; 0 <= i < b_len ==> 0 <= b[i] <= 100;
  requires b_len > 0;
  requires b_len < 100;
  assigns \nothing;
  ensures \result == 0 ==> (a_len != b_len || !arrays_equal(a, b, a_len));
*/
int foo12(int * a, int a_len, int * b, int b_len) {

    if(a_len != b_len) {
        return 0;
    }

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
      loop invariant \forall integer k; i <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop invariant \forall integer k; i <= k < b_len ==> b[k] == \at(b[k], Pre);
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
