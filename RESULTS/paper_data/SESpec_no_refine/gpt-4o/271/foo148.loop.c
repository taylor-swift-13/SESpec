
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);

  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

int foo148(int * arr, int arr_len, int arrSize) {

    int result = 0;
    int count = 0;

    /*@
      loop invariant arrSize == \at(arrSize, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, result, count;
    */
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            count++;
            if (count % 2 != 0) {
                result = arr[i];
            }
        }
    }

    return result;
}
