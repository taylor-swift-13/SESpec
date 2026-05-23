
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(array + (0..array_len-1));
  requires array_len >= 0;
  requires \forall integer i; 0 <= i < array_len - 1 ==> array[i] <= array[i + 1];
  requires -1 <= y - 1 < array_len; // Strengthened precondition to ensure `r` is valid initially.
  ensures -1 <= \result < array_len;
  ensures \result == -1 || array[\result] == x;
  ensures \result == -1 || (\forall integer i; 0 <= i < \result ==> array[i] != x);
  assigns \nothing;
*/
int foo216(int * array, int array_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i <= array_len;
      loop invariant -1 <= r < array_len;
      loop invariant -1 <= k < array_len;
      loop assigns i, r, k;
    */
    while (i <= r) {
        int tmp = (i + r) / 2;
        if (array[tmp] == x) {
            k = tmp;
            i = tmp + 1;
        } else if (array[tmp] < x) {
            i = tmp + 1;
        } else {
            r = tmp - 1;
        }
    }

    return k;
}
