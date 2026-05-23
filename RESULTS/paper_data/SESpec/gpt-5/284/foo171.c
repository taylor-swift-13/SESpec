
/*@ 
  logic integer prefix_min(int* a, integer k) =
    k <= 0 ? a[0] : (prefix_min(a, k-1) < a[k] ? prefix_min(a, k-1) : a[k]);
*/

/*@ 
  logic integer has_increase_from_prefix(int *a, integer k) =
    k <= 0 ? 0
           : (has_increase_from_prefix(a, k-1) != 0 ? 1
              : (a[k] > prefix_min(a, k-1) ? 1 : 0));
*/

/*@
  assigns \nothing;
  ensures arr == \at(arr,Pre);
  ensures arr_len == \at(arr_len,Pre);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
  ensures \result >= 0;
*/
int foo171(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
          loop invariant 0 <= result;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
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
