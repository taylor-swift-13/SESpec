
/*@
  // No extra predicates or logic functions are needed.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo284(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= arr_len;
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop invariant \valid_read(arr + (0 .. arr_len-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
          loop invariant \exists integer t; 0 <= t < i && min == arr[t];
          loop invariant result <= min;
          loop assigns PLACE_HOLDER_ASSIGNMENTS;
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
