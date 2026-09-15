
/*@
  logic integer suffix_min(int *arr, integer i, integer n) =
    i >= n - 1 ? arr[n - 1] :
    (arr[i] <= suffix_min(arr, i + 1, n) ? arr[i] : suffix_min(arr, i + 1, n));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  requires arr_len < 2 || \forall integer i; 0 <= i < arr_len - 1 ==> arr[i] > arr[i + 1];
  assigns \nothing;
  ensures arr_len < 2 ==> \result == 1;
  ensures arr_len >= 2 && (\exists integer i; 0 <= i < arr_len - 1 && arr[i] <= arr[i + 1]) ==> \result == 0;
*/
int foo119(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
