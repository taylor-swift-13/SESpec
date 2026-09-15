
/*@
  logic integer cnt_odd_prefix(int* a, integer hi) =
    hi <= 0 ? 0
            : cnt_odd_prefix(a, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@
  logic integer last_odd_value(int* a, integer hi) =
    hi <= 0 ? 0
            : ((a[hi - 1] % 2 != 0) ? a[hi - 1] : last_odd_value(a, hi - 1));
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo148_c271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant arrSize == \at(arrSize,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k],Pre);
          loop invariant count == cnt_odd_prefix(arr, i);
          loop invariant (count % 2 == 1) ==> (result == last_odd_value(arr, i));
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
