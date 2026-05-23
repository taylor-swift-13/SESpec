
/*@
  logic integer count_pairs(int *arr, integer i) =
    i <= 1 ? 0
           : count_pairs(arr, i - 2) + (arr[i - 2] == arr[i - 1] ? 1 : 0);
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  assigns \nothing;
*/
int foo283(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i % 2 == 0;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; i <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant count_pairs(arr, i) == i / 2;
          loop invariant (i <= n - 1) ==> (n - i == 0 || n - i >= 1);
          loop invariant (i < n - 1) ==> (i + 1 < n);
          loop invariant (0 < \at(n,Pre) - 1) ==> (0 <= i && i <= n);
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
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
