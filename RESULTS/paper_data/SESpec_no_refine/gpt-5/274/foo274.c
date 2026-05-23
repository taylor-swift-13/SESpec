
/*@
  logic integer evensum(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : evensum(a, lo, hi - 1)
               + ((((hi - 1) % 2) == 0) && ((a[hi - 1] % 2) == 0) ? a[hi - 1] : 0);
*/

/*@ logic integer imin(integer x, integer y) = x < y ? x : y; */
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
*/
int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre) ;
          loop assigns i, count;
            */
            for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
            
        return count;
}
