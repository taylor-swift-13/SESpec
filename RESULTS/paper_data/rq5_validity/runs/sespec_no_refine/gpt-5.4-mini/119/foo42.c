
/*@
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures arr_len < 2 ==> \result == 1;
  ensures arr_len >= 2 ==> (\result == 0 || \result == 1);
  ensures arr_len >= 2 && \result == 0 ==> \exists integer i; 0 <= i < arr_len - 1 && arr[i] <= arr[i+1];
  ensures arr_len >= 2 && \result == 1 ==> \forall integer k; 0 <= k < arr_len - 1 ==> arr[k] > arr[k+1];
*/
int foo42(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= arr[k+1];
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
