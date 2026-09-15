
/*@
  logic integer count_arr1_prefix(int* arr1, integer i) =
    i <= 0 ? 0 : count_arr1_prefix(arr1, i - 1) + 1;

  logic integer count_arr2_prefix(int* arr2, integer j) =
    j <= 0 ? 0 : count_arr2_prefix(arr2, j - 1) + 1;
*/

int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        
            
        /*@
          loop invariant 0 <= i;
          loop invariant 0 <= j;
          loop invariant i + j == count;
          loop invariant 0 <= count;
          loop invariant (count < \at(k,Pre)) ==> (i == count_arr1_prefix(arr1, i));
          loop invariant (count < \at(k,Pre)) ==> (j == count_arr2_prefix(arr2, j));
          loop invariant (count < \at(k,Pre)) ==> (k == \at(k,Pre));
          loop invariant (count < \at(k,Pre)) ==> (n == \at(n,Pre));
          loop invariant (count < \at(k,Pre)) ==> (m == \at(m,Pre));
          loop invariant (count < \at(k,Pre)) ==> (arr2_len == \at(arr2_len,Pre));
          loop invariant (count < \at(k,Pre)) ==> (arr2 == \at(arr2,Pre));
          loop invariant (count < \at(k,Pre)) ==> (arr1_len == \at(arr1_len,Pre));
          loop invariant (count < \at(k,Pre)) ==> (arr1 == \at(arr1,Pre));
          loop invariant (!(count < \at(k,Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer q; 0 <= q < arr1_len ==> arr1[q] == \at(arr1[q], Pre);
          loop invariant \forall integer q; 0 <= q < arr2_len ==> arr2[q] == \at(arr2[q], Pre);
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
