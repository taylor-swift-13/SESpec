
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);

  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@ logic integer last_odd_odd(int* a, integer lo, integer hi) =
      lo >= hi ? 0
               : ( (count_odd(a, lo, hi) % 2 != 0) ? a[hi - 1] : last_odd_odd(a, lo, hi - 1) );
*/
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires arrSize >= 0;
  requires 0 <= arrSize <= \at(arr_len,Pre);
  requires \valid(arr + (0 .. arrSize - 1));
  assigns \nothing;   
  ensures \valid(arr + (0 .. arrSize - 1));
  ensures \forall integer k; 0 <= k < arrSize ==> arr[k] == \at(arr[k],Pre);
*/
int foo148(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /*@
          loop invariant 0 <= i <= arrSize;
          loop invariant count == count_odd(arr, 0, i);
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
