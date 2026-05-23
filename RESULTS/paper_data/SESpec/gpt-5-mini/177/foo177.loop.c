
/*@ 
  predicate sorted_nondec(int* a, integer n) =
    \forall integer p, q; 0 <= p <= q < n ==> a[p] <= a[q];
*/

/*@
  requires arr != \null;
  requires arr_len >= 0;
  requires sorted_nondec(arr, arr_len);
  assigns \nothing;
*/
int foo177(int * arr, int arr_len, int array) {

    int i = 0;
    int hi = arr_len - 1;
    int end = 0;
        
    /*@
      loop invariant 0 <= \at(arr_len,Pre);
      loop invariant 0 <= i <= \at(arr_len,Pre);
      loop invariant -1 <= hi <= \at(arr_len,Pre) - 1;
      loop invariant -1 <= end <= \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant 0 <= \at(arr_len,Pre) - 1 ==> sorted_nondec(arr, \at(arr_len,Pre));
      loop assigns end, i, hi;
    */
    while (i <= hi) {
        end = (i + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1
                    || arr[end + 1] != array) {
                return end;
            } else {
                i = end + 1;
            }
        } else if (arr[end] < array) {
            i = end + 1;
        } else {
            hi = end - 1;
        }
    }
            
    return -1;
}
