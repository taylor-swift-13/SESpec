
/*@
  predicate unchanged_array{L1, L2}(int* a, integer lo, integer hi) =
    \forall integer p; lo <= p < hi ==> \at(a[p], L1) == \at(a[p], L2);
*/

/*@
  requires \valid_read(array + (0 .. array_len-1));
  requires 0 <= array_len;
  assigns \nothing;
*/
int foo216(int * array, int array_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant r < y;
      loop invariant unchanged_array{Pre, Here}(array, 0, array_len);
      loop invariant (k != -1) ==> (0 <= k && k <= y-1);

      loop invariant (i <= r) ==> (0 <= i && i <= r && r < y);

      loop assigns k, i, r;
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
