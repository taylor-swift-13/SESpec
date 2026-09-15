
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer count_less{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_less(a, lo, hi - 1, v) + (a[hi - 1] < v ? 1 : 0);
*/

/*@
  logic integer count_greater{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_greater(a, lo, hi - 1, v) + (a[hi - 1] > v ? 1 : 0);
*/

/*@
  requires \at(arr1_len,Pre) > 0 && \at(arr1_len,Pre) < 100;
  requires \at(arr2_len,Pre) > 0 && \at(arr2_len,Pre) < 100;
  requires \valid(arr1 + (0 .. arr1_len - 1));
  requires \valid(arr2 + (0 .. arr2_len - 1));
  ensures \result >= 0 && \result <= arr1_len + arr2_len;
*/
int foo212(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

    int i = 0;
    int j = 0;

    /*@
      loop invariant 0 <= i <= arr1_len;
      loop invariant 0 <= j <= arr2_len;
      loop invariant n == \at(n,Pre);
      loop invariant arr2_len == \at(arr2_len,Pre);
      loop invariant arr2 == \at(arr2,Pre);
      loop invariant arr1_len == \at(arr1_len,Pre);
      loop invariant arr1 == \at(arr1,Pre);
      loop invariant \forall integer k; 0 <= k < arr1_len ==> arr1[k] == \at(arr1[k], Pre);
      loop invariant \forall integer k; 0 <= k < arr2_len ==> arr2[k] == \at(arr2[k], Pre);
      loop assigns i, j;
    */
    while (i < arr1_len && j < arr2_len) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    return i < arr1_len ? i : j;
}
