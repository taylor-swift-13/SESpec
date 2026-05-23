
/* No additional predicates or logic functions are needed. */

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == 1 ==> (arr_len < 2 || (\forall integer k2; 0 <= k2 < arr_len-1 ==> arr[k2] > arr[k2+1]));
  ensures 0 <= \result <= 1;
  ensures \forall integer t; 0 <= t < arr_len ==> arr[t] == \at(arr[t], Pre);
*/
int foo119(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= n;
              loop invariant \valid(&arr[0] + (0..n-1));
              loop invariant \forall integer k; 0 <= k < i ==> arr[k] > arr[k+1];
              loop invariant (i >= n) ==> (\forall integer k; 0 <= k < n-1 ==> arr[k] > arr[k+1]);
              loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
              loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
