
/*@
  logic integer odd_count(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(arr, lo, hi - 1) + ((arr[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@ 
  requires arrSize > 0 && arrSize < 100;
  requires \valid(arr + (0 .. arrSize - 1));
  assigns \nothing;
*/
int foo271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant count == odd_count(arr, 0, i);
          loop invariant 0 <= count <= i;
          loop invariant arrSize == \at(arrSize,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k], Pre);
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
