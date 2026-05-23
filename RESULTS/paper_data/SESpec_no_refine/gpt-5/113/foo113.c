
/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures \result == 1 <==> (arr_len < 2 || (\forall integer k; 0 <= k < arr_len-1 ==> arr[k] < arr[k+1]));
*/
int foo113(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= n;
              loop invariant \forall integer k; 0 <= k < i ==> arr[k] < arr[k+1];
              loop assigns \nothing;
              loop variant n - i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
            
        return 1;
}
