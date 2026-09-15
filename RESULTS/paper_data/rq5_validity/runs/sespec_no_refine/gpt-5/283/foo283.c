
/*@
  logic integer pairs_equal_prefix{L}(int* a, integer i) =
    i <= 0 ? 1
           : (a[i-1] == a[i] ? pairs_equal_prefix{L}(a, i-2) : 0);
*/

/*@
  assigns \nothing;
  ensures arr == \at(arr,Pre) && arr_len == \at(arr_len,Pre) && n == \at(n,Pre);
          ||
          ((\forall integer j; 0 <= j < n-1 ==> (\exists integer t; j == 2*t) ==> arr[j] == arr[j+1]) && \result == arr[n-1]);
  ensures \result == \result;
*/
int foo283(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns i;
            */
            while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
