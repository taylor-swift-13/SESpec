
/*@
  requires arr != \null;
  requires \valid(arr + (0 .. arr_len));
  ensures \result == 0 || \result == 1;
  ensures \result == 1 ==> (\forall integer k; 0 <= k < arr_len - 1 ==> arr[k] > arr[k+1]);
  ensures \result == 0 ==> (\exists integer k; 0 <= k < arr_len - 1 && arr[k] <= arr[k+1]);
*/

int foo119(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i;
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
