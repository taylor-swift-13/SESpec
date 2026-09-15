
/*@
  logic integer pair_count_prefix(int* a, integer upto, integer n, integer s) =
    \sum(integer u, 0, upto, \sum(integer v, u+1, n, (a[u] + a[v] == s)));
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo252(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant sum == \at(sum,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant 0 <= count;
          loop invariant count == pair_count_prefix(arr, i, n, sum);
          loop assigns i, j, count;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= j <= n;
          loop invariant j >= i + 1;
          loop invariant count >= 0;
          loop invariant count == \sum(integer u, 0, i, 
                                   \sum(integer v, u+1, n, (arr[u] + arr[v] == sum)));
          loop invariant count + \sum(integer v, j, n, (arr[i] + arr[v] == sum))
                                == \sum(integer v, i+1, n, (arr[i] + arr[v] == sum))
                                   + \sum(integer u, 0, i, 
                                         \sum(integer v, u+1, n, (arr[u] + arr[v] == sum)));
          loop assigns count, j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
            
        return count;
}
