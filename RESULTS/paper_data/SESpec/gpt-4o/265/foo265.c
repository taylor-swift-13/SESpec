
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? -1
             : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@
  requires \valid(ints + (0..ints_len-1));
  requires ints_len >= 0;
  requires array >= 0;
  assigns \nothing;
  ensures \forall integer k; 0 <= k < array ==> (ints[k] % 2 != 0 ==> last_odd(ints, 0, k + 1) == ints[k]);
*/
int foo265(int * ints, int ints_len, int array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant 0 <= index <= array;
      loop invariant 0 <= start <= count_odd(ints, 0, index);
      loop invariant ret == (start % 2 != 0 ? last_odd(ints, 0, index) : ret);
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] == \at(ints[k], Pre));
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> count_odd(ints, 0, k + 1) == count_odd(ints, 0, k) + 1);
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 ==> count_odd(ints, 0, k + 1) == count_odd(ints, 0, k));
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 != 0 ==> last_odd(ints, 0, k + 1) == ints[k]);
      loop invariant \forall integer k; 0 <= k < index ==> (ints[k] % 2 == 0 ==> last_odd(ints, 0, k + 1) == last_odd(ints, 0, k));
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
