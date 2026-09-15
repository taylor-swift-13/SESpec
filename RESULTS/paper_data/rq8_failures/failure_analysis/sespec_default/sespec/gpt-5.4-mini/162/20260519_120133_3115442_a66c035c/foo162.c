
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns arr[0..n-1];
  ensures \forall integer k; 0 <= k < n ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1 || (0 <= arr[k] - 1 < n));
*/

int foo162(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < n ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1 || (0 <= arr[k] - 1 < n));
          loop assigns i, arr[0..n-1];
            */
            while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i < n) ==> (\forall integer k; 0 <= k < i ==> arr[k] == k + 1);
          loop invariant \forall integer k; 0 <= k < n ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1 || (0 <= arr[k] - 1 < n));
          loop assigns i;
            */
            for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
            
        return n + 1;
}
