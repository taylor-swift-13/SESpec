
/*@
  logic integer max_in_prefix(int* arr, integer len) =
    len <= 0 ? arr[0] : (arr[len - 1] > max_in_prefix(arr, len - 1) ? arr[len - 1] : max_in_prefix(arr, len - 1));
*/

/*@ 
  logic integer min_in_prefix(int* arr, integer len) =
    len <= 0 ? arr[0] : (arr[len - 1] < min_in_prefix(arr, len - 1) ? arr[len - 1] : min_in_prefix(arr, len - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires arr_len > 0; // Strengthened precondition to ensure valid array length
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == max_in_prefix(arr, arr_len) - min_in_prefix(arr, arr_len);
*/
int foo234(int * arr, int arr_len) {

    int big = arr[0];
    int sum = arr[0];

    /*@
      loop invariant 1 <= n <= arr_len;
      loop invariant 0 <= n - 1 < arr_len; // Ensures valid indexing
      loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
      loop invariant big == max_in_prefix(arr, n);
      loop invariant sum == min_in_prefix(arr, n);
      loop assigns big, sum;
      loop variant arr_len - n;
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
