
/*@ predicate unchanged_arr1(int *arr1, integer arr1_len) =
      \forall integer t; 0 <= t < arr1_len ==> arr1[t] == \at(arr1[t], Pre);

    predicate unchanged_arr2(int *arr2, integer arr2_len) =
      \forall integer t; 0 <= t < arr2_len ==> arr2[t] == \at(arr2[t], Pre);
*/

int foo32(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        
            
        /*@
          loop invariant (count < \at(k,Pre)) ==> (i == 0 && j == 0);
          loop invariant (count < \at(k,Pre)) ==> (0 <= i <= m && 0 <= j <= n);
          loop invariant (count < \at(k,Pre)) ==> (unchanged_arr1(arr1, arr1_len));
          loop invariant (count < \at(k,Pre)) ==> (unchanged_arr2(arr2, arr2_len));
          loop invariant (!(count < \at(k,Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant unchanged_arr1(arr1, arr1_len);
          loop invariant unchanged_arr2(arr2, arr2_len);
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
