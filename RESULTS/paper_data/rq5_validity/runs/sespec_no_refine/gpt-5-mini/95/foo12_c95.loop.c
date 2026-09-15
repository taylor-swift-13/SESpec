
/*@
  // Predicate: arrays a and b are equal on interval [lo, hi)
  logic boolean eq_range(int* a, int* b, integer lo, integer hi) =
    lo >= hi ? \true
             : (a[hi-1] == b[hi-1]) && eq_range(a, b, lo, hi-1);
*/

int foo12_c95(int * a, int a_len, int * b, int b_len) {

    if(a_len != b_len) {
        return 0;
    }

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant eq_range(a, b, 0, i);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == a[k]; // a unchanged (trivial)
      loop invariant \forall integer k; 0 <= k < b_len ==> b[k] == b[k]; // b unchanged (trivial)
      loop assigns i;
    */
    for(int i = 0; i < a_len; i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
