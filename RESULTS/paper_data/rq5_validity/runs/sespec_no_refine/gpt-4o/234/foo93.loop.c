
/*@
  logic integer max_element(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo - 1] : (arr[hi - 1] > max_element(arr, lo, hi - 1) ? arr[hi - 1] : max_element(arr, lo, hi - 1));

  logic integer min_element(int* arr, integer lo, integer hi) =
    lo >= hi ? arr[lo - 1] : (arr[hi - 1] < min_element(arr, lo, hi - 1) ? arr[hi - 1] : min_element(arr, lo, hi - 1));
*/

/*@
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  ensures \result == max_element(arr, 0, \at(arr_len,Pre)) - min_element(arr, 0, \at(arr_len,Pre));
*/
int foo93(int * arr, int arr_len) {

    int big = arr[0];
    int sum = arr[0];
    
    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop assigns n, big, sum;
    */
    for (int n = 1; n < arr_len; n++) {
        if (arr[n] > big) {
            big = arr[n];
        }
        if (arr[n] < sum) {
            sum = arr[n];
        }
    }
    
    return big - sum;
}
