
/*@
  requires arr1_len >= 0 && arr2_len >= 0;
  requires 0 <= m <= arr1_len;
  requires 0 <= n <= arr2_len;
  requires 0 <= k;
  requires \valid_read(arr1 + (0 .. arr1_len - 1));
  requires \valid_read(arr2 + (0 .. arr2_len - 1));
*/

int foo178(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        /*@
          loop invariant 0 <= count <= k;
          loop invariant 0 <= i <= m;
          loop invariant 0 <= j;
          loop invariant i + j == count;
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
