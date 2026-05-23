
/*@
  logic integer max(int a, int b) = a > b ? a : b;

  logic integer min_value(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[0] : (arr[hi - 1] < min_value(arr, lo, hi - 1) ? arr[hi - 1] : min_value(arr, lo, hi - 1));

  logic integer max_value(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[0] : (arr[hi - 1] > max_value(arr, lo, hi - 1) ? arr[hi - 1] : max_value(arr, lo, hi - 1));
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  ensures \result == max_value(arr, 0, \at(arr_len,Pre));
*/
int foo171(int * arr, int arr_len) {

    int result = 0;
    int min = arr[0];

    /*@
      loop invariant 1 <= i <= \at(arr_len,Pre);
      loop invariant min == min_value(arr, 0, i);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop assigns i, result, min;
    */
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] > min) {
            result = result > min ? result : min;
        } else {
            min = arr[i];
        }
    }

    return result;
}
