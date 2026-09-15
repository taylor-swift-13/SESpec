
/*@
logic integer row_sum{L}(int *arr, integer i, integer j) =
  (j <= i + 1 ? 0 : row_sum(arr, i, j - 1) + (arr[i] ^ arr[j - 1]));
*/

/*@
logic integer prefix_sum(int *arr, integer i, integer n) =
  (i >= n ? 0 : row_sum(arr, i, n) + prefix_sum(arr, i + 1, n));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
*/

int foo275(int * arr, int arr_len, int n) {

        int sum = 0;
        
        /*@
          loop invariant 0 <= i;
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, sum;
        */
        for (int i = 0; i < arr_len; i++) {
            
            /*@
              loop invariant 0 <= j <= arr_len;
              loop invariant i + 1 <= j <= arr_len;
              loop assigns j, sum;
            */
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
            
        }
            
        return sum;
}
