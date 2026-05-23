
/*@ 
  predicate ValidRange(int *a, integer n) = \valid_read(a + (0..n-1));
*/

/*@
  requires \true;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo36_c113(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /*@
          loop invariant 0 <= i <= n;
          loop invariant ValidRange(arr, n);
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] < arr[k+1];
          loop invariant (i < n) ==> \valid_read(arr + i) && \valid_read(arr + (i+1));
          loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n-1 ==> arr[k] < arr[k+1]);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
        */
            for (int i = 0; i < n; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
            
        return 1;
}
