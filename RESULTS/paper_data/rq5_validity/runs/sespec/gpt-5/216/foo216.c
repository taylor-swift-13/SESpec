
/*@
  requires array_len >= 0;
  requires \valid_read(array + (0 .. array_len-1));
  requires \forall integer p, q; 0 <= p <= q < array_len ==> array[p] <= array[q];
  requires 0 <= y <= array_len;
  ensures -1 <= \result < array_len;
  ensures \result != -1 ==> array[\result] == x;
  assigns \nothing;
*/
int foo216(int * array, int array_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i <= array_len;
      loop invariant -1 <= r && r < array_len;
      loop invariant k == -1 || (0 <= k < array_len && array[k] == x);
      loop invariant \forall integer p, q; 0 <= p <= q < array_len ==> array[p] <= array[q];
      loop invariant \forall integer t; 0 <= t < array_len ==> array[t] == \at(array[t], Pre);
      loop assigns k, i, r;
      loop variant r - i + 1;
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
