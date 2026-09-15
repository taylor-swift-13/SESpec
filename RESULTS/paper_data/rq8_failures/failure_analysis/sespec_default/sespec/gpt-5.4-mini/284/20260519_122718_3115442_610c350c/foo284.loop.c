
/*@ 
  logic integer max2(integer a, integer b) = a > b ? a : b;
*/

int foo284(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        
            
        /*@
          loop invariant result >= 0;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
