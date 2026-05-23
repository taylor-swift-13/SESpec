
/*@
  requires n >= 1;
  requires \valid_read(arr + (0 .. n-1));
*/
int foo283(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i % 2 == 0;
          loop invariant (0 < \at(n,Pre) - 1) ==> (0 <= i <= n);
          loop invariant (0 < \at(n,Pre) - 1) ==> (i % 2 == 0);
          loop invariant (0 < \at(n,Pre) - 1) ==> (i <= n);
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((i == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
