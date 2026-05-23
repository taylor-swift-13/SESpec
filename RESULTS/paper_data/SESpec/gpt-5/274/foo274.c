
/*@
  logic integer sum_even_even(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_even(a, lo, hi - 1)
               + (((hi - 1) % 2 == 0) && (a[hi - 1] % 2 == 0) ? a[hi - 1] : 0);
*/

/*@ 
  requires n >= 0;
  requires \valid_read(arr + (0 .. (n > 0 ? n - 1 : 0) ));
  assigns \nothing;   
  ensures \result == sum_even_even(arr, 0, n);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == sum_even_even(arr, 0, n);
  ensures arr == \at(arr, Pre);
  ensures arr_len == \at(arr_len, Pre);
  ensures n == \at(n, Pre);
    ensures \result == sum_even_even(arr, 0, n);  
*/
int foo274(int * arr, int arr_len, int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant n == \at(n,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant \valid_read(arr + (0 .. (n > 0 ? n - 1 : 0)));
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant count == sum_even_even(arr, 0, i);
          loop invariant (i < \at(n,Pre)) ==> (0 <= i < n);
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
