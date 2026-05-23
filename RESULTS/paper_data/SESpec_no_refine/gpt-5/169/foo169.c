
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  assigns \nothing;
  ensures \result == 0
        || (\exists integer k; 1 <= k < arr_len && arr[k-1] > arr[k] && \result == k);
*/
int foo169(int * arr, int arr_len) {

    int r = 0;
    int stop = arr_len - 1;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant 0 <= \at(arr_len,Pre) && \at(arr_len,Pre) < 100;
      loop invariant -1 <= stop <= \at(arr_len,Pre) - 1;
      loop invariant 0 <= r <= \at(arr_len,Pre);
      loop invariant r <= stop + 1;
      loop assigns r, stop;
    */
    while (r <= stop) {
        int i = r + (stop - r) / 2;
        if (i < stop
                && arr[i] > arr[i + 1]) {
            return i + 1;
        } else if (i > r
                && arr[i] < arr[i - 1]) {
            return i;
        }
        if (arr[i] >= arr[r]) {
            r = i + 1;
        } else {
            stop = i - 1;
        }
    }
            
    return 0;
}
