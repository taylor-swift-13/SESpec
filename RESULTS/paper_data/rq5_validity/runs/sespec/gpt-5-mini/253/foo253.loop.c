
/*@
predicate valid_arr{L}(int *a, integer len) = \valid(a+(0 .. len-1));
*/

/*@
  logic integer invs_prefix(int *a, integer n, integer i) =
    i <= 0 ? 0
          : invs_prefix(a, n, i-1)
            + ( (i-1) < n
                ? (\sum integer t; (i-1)+1 <= t < n ? (a[i-1] > a[t] ? 1 : 0) : 0)
                : 0);
*/
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo253(int * arr, int arr_len, int n) {

        int invCount = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (i < \at(n,Pre)) ==> (0 <= i && i < \at(n,Pre));
          loop invariant (i < \at(n,Pre)) ==> (invCount == invs_prefix(arr, \at(n,Pre), i));
          loop invariant (!(i < \at(n,Pre))) ==> ((invCount == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> 0 <= arr[k] <= 100;
          loop assigns i, j, invCount;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 0 <= i && i <= n;
            loop invariant valid_arr(arr, arr_len);
            loop invariant 0 <= invCount;
            loop invariant invCount == invs_prefix(arr, n, i);
            loop assigns i, invCount;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
            
        }
            
        return invCount;
}
