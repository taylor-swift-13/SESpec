
/*@
requires 0 <= array_len;
requires 0 <= y <= array_len;
requires \valid(array + (0 .. array_len-1));
requires \forall integer p, q; 0 <= p <= q < array_len ==> array[p] <= array[q];
assigns \nothing;
ensures -1 <= \result < y;
ensures \result == -1 || array[\result] == x;
*/
int foo216(int * array, int array_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i <= y;
      loop invariant -1 <= r < y;
      loop invariant i <= r + 1;
      loop invariant k == -1 || (0 <= k < y && array[k] == x);
      loop assigns i, r, k;
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
