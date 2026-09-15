
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires n >= 0;
  requires \valid_read(array + (0..n-1));
  assigns \nothing; // except 'location' which we declare here as a local
*/
int foo53(int search, int array[], int n) {

    int c;
    int location = -1;

    /*@
      loop invariant 0 <= c <= n;
      loop invariant -1 <= location < c || location == -1;
      loop invariant \forall integer k; 0 <= k < (location == -1 ? c : location) ==> array[k] != search;
      loop invariant location != -1 ==> (0 <= location < c && array[location] == search);
      loop invariant \forall integer k; 0 <= k < n ==> array[k] == \at(array[k], Pre);
      loop invariant \forall integer v; count_eq(array, 0, n, v) == \at(count_eq(array, 0, n, v), Pre);
      loop assigns c, location;
    */
    for (c = 0; c < n; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }

    if (c == n) {
        location = -1;
    }
    return location;
}
