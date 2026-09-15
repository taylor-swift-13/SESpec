
/*@
  logic integer count_arr1_le_prefix(int* a, integer len, integer bound, integer i) =
    i <= 0 ? 0
            : count_arr1_le_prefix(a, len, bound, i - 1) + (a[i - 1] <= bound ? 1 : 0);

  logic integer count_arr2_lt_prefix(int* a, integer len, integer bound, integer i) =
    i <= 0 ? 0
            : count_arr2_lt_prefix(a, len, bound, i - 1) + (a[i - 1] < bound ? 1 : 0);
*/

int foo32(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (!(count < \at(k,Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t],Pre);
          loop invariant \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t],Pre);
          loop assigns count, i, j;
            */
            for (int count = 0; count < k; count++) {
            if (i < m && (j >= n || arr1[i] <= arr2[j])) {
                if (count == k - 1) {
                    return arr1[i];
                }
                i++;
            } else {
                if (count == k - 1) {
                    return arr2[j];
                }
                j++;
            }
        }
            
        return -1;
}
