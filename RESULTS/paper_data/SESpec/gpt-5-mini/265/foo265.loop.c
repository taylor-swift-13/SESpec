
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  requires \valid_read(ints + (0 .. ints_len-1));
  requires ints_len >= 0;
  requires array >= 0;
*/
int foo265(int * ints, int ints_len, int array) {

    int ret = 0;
    int start = 0;
            
    /*@
      loop invariant 0 <= index;
      loop invariant index <= \at(array,Pre);

      loop invariant 0 <= start <= index;
      loop invariant start == count_odd(ints, 0, index);

      loop invariant (ret == 0) || (\exists integer k; 0 <= k < index &&
                        (count_odd(ints, 0, k+1) % 2 == 1) && ints[k] == ret);

      loop invariant (!(index < array)) ==> (start == count_odd(ints, 0, array));
      loop invariant (!(index < array)) ==> ((ret == 0) || (\exists integer k; 0 <= k < array &&
                        (count_odd(ints, 0, k+1) % 2 == 1) && ints[k] == ret));

      loop invariant array == \at(array,Pre);
      loop invariant ints_len == \at(ints_len,Pre);
      loop invariant ints == \at(ints,Pre);
      loop invariant \forall integer k; 0 <= k < ints_len ==> ints[k] == \at(ints[k],Pre);

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
