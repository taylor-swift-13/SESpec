
/*@ 
  logic integer odd_prefix_count(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_prefix_count(arr, lo, hi - 1) + ((arr[hi - 1] % 2 != 0) ? 1 : 0);

  logic integer odd_prefix_result(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : ((odd_prefix_count(arr, lo, hi) % 2 != 0) ? arr[hi - 1] : odd_prefix_result(arr, lo, hi - 1));
*/

/*@ 
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns result, count, i;
  ensures result == odd_prefix_result(arr, 0, arrSize);
  ensures \result == odd_prefix_result(arr, 0, arrSize);
*/
int foo148(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant arrSize == \at(arrSize,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k],Pre);
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
