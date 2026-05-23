
/*@ */

 /*@
requires arr != \null;
requires 0 < n;
requires \valid_read(arr + (0 .. n-1));
requires k != 0;
assigns \nothing;
ensures \result == foo167_model(arr, n, k);
ensures \result == -1 <==> (\exists integer i; 0 <= i < n && (max_prefix(arr, n) - arr[i]) % k != 0);
ensures \result != -1 ==> \result >= 0;
ensures \forall integer i; 0 <= i < n ==> arr[i] == \at(arr[i], Pre);
ensures \result == \null ==> \false;
*/

int foo167(int * arr, int arr_len, int n, int k) {

        int max1 = arr[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n;
          loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max1;
          loop assigns i, max1;
            */
            for (int i = 1; i < n; i++) {
            if (arr[i] > max1) {
                max1 = arr[i];
            }
        }
            
        int res = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer j; 0 <= j < i ==> (max1 - arr[j]) % k == 0;
          loop invariant res == \sum(0, i-1, \lambda integer t; (max1 - arr[t]) / k);
          loop assigns i, res;
            */
            for (int i = 0; i < n; i++) {
            if ((max1 - arr[i]) % k != 0) {
                return -1;
            } else {
                res += (max1 - arr[i]) / k;
            }
        }
            
        return res;
}
