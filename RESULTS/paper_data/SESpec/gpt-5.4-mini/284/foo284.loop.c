
/*@
  requires arr_len >= 1;
  requires \valid_read(arr + (0 .. arr_len-1));
*/
int foo284(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        
        /*@
          loop invariant 1 <= i <= arr_len + 1;
          loop invariant 0 <= result;
          loop invariant arr[0] >= min;
          loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
          loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
          loop invariant \forall integer k; 0 <= k < i ==> result >= 0;
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
