/*@ 
  predicate is_non_decreasing{L}(int *a, integer len) =
    \forall integer i, j; 0 <= i < j < len ==> a[i] <= a[j];

  logic integer count_less{L}(int *a, integer len, integer v) =
    \sum_{integer i = 0; i < len; i++} (a[i] < v ? 1 : 0);

  logic integer count_leq{L}(int *a, integer len, integer v) =
    \sum_{integer i = 0; i < len; i++} (a[i] <= v ? 1 : 0);
*/

int findKth(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k);

/*@ 
  requires arr1_len >= 0;
  requires arr2_len >= 0;
  requires 0 <= m <= arr1_len;
  requires 0 <= n <= arr2_len;
  requires m == 0 || \valid_read(arr1 + (0 .. m-1));
  requires n == 0 || \valid_read(arr2 + (0 .. n-1));
  requires is_non_decreasing(arr1, m);
  requires is_non_decreasing(arr2, n);
  requires 1 <= k <= m + n;

  assigns \nothing;

  ensures
    (\exists integer p; 0 <= p < m && \result == arr1[p]) ||
    (\exists integer q; 0 <= q < n && \result == arr2[q]);

  ensures
    count_less(arr1, m, \result) + count_less(arr2, n, \result) <= k - 1 &&
    count_leq(arr1, m, \result) + count_leq(arr2, n, \result) >= k;
*/
int findKth(int * arr1, int arr1_len, int * arr2, int arr2_len, int m, int n, int k) {

        int i = 0;
        int j = 0;

        /*@
          loop invariant 0 <= i <= m;
          loop invariant 0 <= j <= n;
          loop invariant 0 <= count <= k;
          loop invariant i + j == count;
          loop assigns i, j, count;
          loop variant k - count;
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
