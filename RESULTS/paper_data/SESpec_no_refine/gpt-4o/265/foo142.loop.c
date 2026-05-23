
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@
  requires \at(ints_len, Pre) > 0 && \at(ints_len, Pre) < 100;
  requires \valid(ints + (0 .. ints_len - 1));
  ensures \result == 0 || (\exists integer i; 0 <= i < ints_len && ints[i] == \result && ints[i] % 2 != 0);
  ensures \result == 0 || \result == last_odd(ints, 0, ints_len);
*/
int foo142(int * ints, int ints_len, int array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> count_odd(ints, 0, k + 1) > count_odd(ints, 0, k));
      loop invariant array == \at(array, Pre);
      loop invariant ints_len == \at(ints_len, Pre);
      loop invariant ints == \at(ints, Pre);
      loop assigns index, ret, start;
    */
    for (int index = 0; index < array; index++) {
        if (ints[index] % 2 != 0) {
            start++;
            if (start % 2 != 0) {
                ret = ints[index];
            }
        }
    }

    return ret;
}
