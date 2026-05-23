
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(arr + (0..len-1));
  requires len >= 0;
  ensures \forall integer k; 0 <= k < len ==> arr[k] == \at(arr[k], Pre);
  ensures \result == \null ==> count_eq(arr, 0, len, val) == 0;
  ensures \result != \null ==> count_eq(arr, 0, \result - arr, val) == 0 && *\result == val;
  assigns \nothing;
*/
int * search(int * arr, int len, int val) {
    int i = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop invariant \forall integer k; 0 <= k < len ==> arr[k] == \at(arr[k], Pre);
      loop invariant count_eq(arr, 0, i, val) == 0;
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        if (arr[i] == val) return arr + i;
        i = i + 1;
    }

    return (int *)0;
}
