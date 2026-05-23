
/*@
  logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi - 1] % 2) != 0 ? 1 : 0);

  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ((a[hi - 1] % 2) != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires 0 <= arrSize <= arr_len;
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 0 || \result % 2 != 0;
*/
int foo271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= count <= i;
          loop invariant count == odd_count(arr, 0, i);
          loop invariant count == 0 ==> result == 0;
          loop invariant count > 0 ==> result == 0 || result % 2 != 0;
          loop invariant count % 2 != 0 ==> result == last_odd(arr, 0, i);
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
