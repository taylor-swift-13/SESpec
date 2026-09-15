
/*@
  logic integer cnt_odd{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cnt_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);

  logic integer last_odd_or_zero{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd_or_zero(a, lo, hi - 1));
*/

int foo271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arrSize == \at(arrSize,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arrSize == \at(arrSize,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arrSize,Pre) ==> arr[k] == \at(arr[k],Pre) ;
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
