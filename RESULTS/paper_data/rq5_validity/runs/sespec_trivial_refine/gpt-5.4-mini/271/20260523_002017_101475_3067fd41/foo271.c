
        /*@
        */

/*@
  requires 0 <= arrSize;
  requires 0 <= arrSize <= arr_len;
  requires \valid_read(arr + (0 .. arrSize - 1));
  assigns \nothing;
  ensures \result == odd_pick{Pre}(arr, arrSize);
  ensures arrSize == 0 ==> \result == 0;
  ensures odd_count{Pre}(arr, arrSize) == 0 ==> \result == 0;
  ensures odd_count{Pre}(arr, arrSize) > 0 ==> \result != 0;
  ensures odd_count{Pre}(arr, arrSize) > 0 ==> \result % 2 != 0;
  ensures \result == 0 <==> odd_count{Pre}(arr, arrSize) == 0;
  ensures odd_count{Pre}(arr, arrSize) > 0 ==> \exists integer j; 0 <= j < arrSize && arr[j] % 2 != 0 && \result == arr[j];
  ensures \forall integer i; 0 <= i < arrSize ==> arr[i] == \at(arr[i], Pre);
*/
int foo271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /*@ 
          loop invariant 0 <= i <= arrSize;
          loop invariant 0 <= count <= i;
          loop invariant count <= arrSize;
          loop invariant count == ( \numof int k; 0 <= k < i && arr[k] % 2 != 0 );
          loop invariant result == 0 || (\exists integer j; 0 <= j < i && arr[j] % 2 != 0 && result == arr[j]);
          loop assigns i, count, result;
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
