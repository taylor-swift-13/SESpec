
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer count_valid_positions(int* a, integer lo, integer hi, integer array) =
    lo >= hi ? 0
             : count_valid_positions(a, lo, hi - 1, array) +
               ((a[hi - 1] > 0 && a[hi - 1] <= array) ? 1 : 0);
*/

/*@
  predicate is_permutation{L1, L2}(int* a, integer len) =
    \forall integer v; 0 <= v <= len ==>
      count_eq{L1}(a, 0, len, v) == count_eq{L2}(a, 0, len, v);
*/

/*@
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires \valid(positions + (0 .. positions_len - 1));
  requires array > 0;
  ensures \forall integer i; 0 <= i < positions_len ==> 0 <= positions[i] <= array;
  ensures \forall integer v; 0 <= v <= array ==>
            count_eq(positions, 0, positions_len, v) == \at(count_eq(positions, 0, positions_len, v), Pre);
  assigns positions[0 .. positions_len - 1];
*/
int foo11(int * positions, int positions_len, int array) {

    int ret = 0;

    /*@
      loop invariant 0 <= ret <= array;
      loop invariant array == \at(array,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \forall integer i; 0 <= i < ret ==> 
                       (positions[i] == i + 1 || positions[i] <= 0 || positions[i] > array);
      loop assigns ret, positions[0 .. positions_len - 1];
    */
    while (ret < array) {
        if (positions[ret] <= 0 || positions[ret] > array
                || positions[ret] == ret + 1) {
            ret++;
        } else {
            int index = positions[ret];
            positions[ret] = positions[index - 1];
            positions[index - 1] = index;
        }
    }

    /*@
      loop invariant 0 <= ret <= array;
      loop invariant \forall integer i; 0 <= i < ret ==> positions[i] == i + 1;
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (positions[ret] != ret + 1) {
            return ret + 1;
        }
    }

    return array + 1;
}
