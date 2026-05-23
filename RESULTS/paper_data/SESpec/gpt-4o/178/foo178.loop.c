
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);

  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires \at(arr1_len, Pre) > 0 && \at(arr1_len, Pre) < 100;
  requires \at(arr2_len, Pre) > 0 && \at(arr2_len, Pre) < 100;
  requires m == arr1_len && n == arr2_len;
  requires k > 0 && k <= m + n;
  requires m >= 0 && n >= 0 && k >= 0;
*/
int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        /*@
          loop invariant 0 <= count <= k;
          loop invariant 0 <= i <= m;
          loop invariant 0 <= j <= n;
          loop invariant i + j == count;
          loop invariant (!(count < k)) ==> ((j == 0)&&(i == 0)&&(k == \at(k,Pre))&&(n == \at(n,Pre))&&(m == \at(m,Pre))&&(arr2_len == \at(arr2_len,Pre))&&(arr2 == \at(arr2,Pre))&&(arr1_len == \at(arr1_len,Pre))&&(arr1 == \at(arr1,Pre)));
          loop invariant k == \at(k,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant m == \at(m,Pre);
          loop invariant arr2_len == \at(arr2_len,Pre);
          loop invariant arr2 == \at(arr2,Pre);
          loop invariant arr1_len == \at(arr1_len,Pre);
          loop invariant arr1 == \at(arr1,Pre);
          loop invariant \forall integer x; 0 <= x < arr1_len ==> arr1[x] == \at(arr1[x], Pre);
          loop invariant \forall integer y; 0 <= y < arr2_len ==> arr2[y] == \at(arr2[y], Pre);
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
