
/*@ 
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0 : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires array <= 0 || (0 <= array <= positions_len && \valid(positions + (0 .. array - 1)));
  assigns positions[0 .. (array > 0 ? array - 1 : -1)];
  ensures array <= 0 ==> \result == array + 1;
  ensures array > 0 ==> ( (\result == array + 1 && \forall integer k; 0 <= k < array ==> positions[k] == k + 1)
                          || (1 <= \result <= array && positions[\result - 1] != \result) );
  ensures array <= 0 || \valid(\old(positions) + (0 .. array - 1));
  ensures \result == (array <= 0 ? array + 1 : \result);
*/
int foo12_c161(int * positions, int positions_len, int array) {

    int ret = 0;

    /*@
      loop invariant 0 <= ret;
      loop invariant (ret <= array) || (array < 0);
      loop invariant array == \at(array,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop assigns ret, positions[0 .. array-1];
    */
    while (ret < array) {
        if (positions[ret] <= 0 || positions[ret] > array
                || positions[ret] == ret + 1) {
            ret++;
        } else {
            int j = positions[ret];
            positions[ret] = positions[j - 1];
            positions[j - 1] = j;
        }
    }

    /*@
      loop invariant 0 <= ret;
      loop invariant (ret <= array) || (array < 0);
      loop invariant \forall integer k; 0 <= k < ret ==> positions[k] == k + 1;
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (positions[ret] != ret + 1) {
            return ret + 1;
        }
    }

    return array + 1;
}
