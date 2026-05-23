
/*@
  logic integer max_prefix(int* arr, integer lo, integer hi) =
    lo >= hi ? 0 : (hi == lo + 1 ? arr[lo] : (arr[hi - 1] > max_prefix(arr, lo, hi - 1) ? arr[hi - 1] : max_prefix(arr, lo, hi - 1)));
*/

/*@
  logic integer sum_differences(int* arr, integer lo, integer hi, integer max1, integer k) =
    lo >= hi ? 0 : ((max1 - arr[lo]) % k != 0 ? -1 : (max1 - arr[lo]) / k + sum_differences(arr, lo + 1, hi, max1, k));
*/

/*@
  requires \valid_read(arr + (0..arr_len-1));
  requires arr_len > 0;
  requires n > 0 && n <= arr_len;
  requires k > 0;
  assigns \nothing;
  
  
  ensures \forall integer j; 0 <= j < arr_len ==> arr[j] == \at(arr[j], Pre);
*/
int foo167(int * arr, int arr_len, int n, int k) {

    int max1 = arr[0];
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant \forall integer j; 0 <= j < i ==> max1 >= arr[j];
      loop invariant max1 == max_prefix(arr, 0, i);
      loop invariant \forall integer j; 0 <= j < arr_len ==> arr[j] == \at(arr[j], Pre);
      loop assigns i, max1;
    */
    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max1 = arr[i];
        }
    }
    
    int res = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer j; 0 <= j < arr_len ==> arr[j] == \at(arr[j], Pre);
      loop assigns i, res;
    */
    for (int i = 0; i < n; i++) {
        if ((max1 - arr[i]) % k != 0) {
            return -1;
        } else {
            res += (max1 - arr[i]) / k;
        }
    }
    
    return res;
}
