
/*@
  requires arr1_len >= 0 && arr2_len >= 0;
  requires 0 <= m <= arr1_len;
  requires 0 <= n <= arr2_len;
  requires 0 <= k <= m + n;

  requires arr1_len == 0 || \valid_read(arr1 + (0 .. arr1_len - 1));
  requires arr2_len == 0 || \valid_read(arr2 + (0 .. arr2_len - 1));

  requires \forall integer p, q; 0 <= p < q < m ==> arr1[p] <= arr1[q];
  requires \forall integer p, q; 0 <= p < q < n ==> arr2[p] <= arr2[q];

  requires \forall integer p; 0 <= p < m ==> arr1[p] != -1;
  requires \forall integer q; 0 <= q < n ==> arr2[q] != -1;

  assigns \nothing;

  ensures k == 0 ==> \result == -1;
*/
int foo178(int *arr1, int arr1_len, int *arr2, int arr2_len, int m, int n, int k) {

  int i = 0;
  int j = 0;

  /*@
    loop invariant 0 <= count <= k;
    loop invariant 0 <= i <= m;
    loop invariant 0 <= j <= n;
    loop invariant i + j == count;
    loop invariant count < k ==> (i < m || j < n);
    loop assigns count, i, j;
  */
  for (int count = 0; count < k; count++) {
    if (i < m && (j >= n || arr1[i] <= arr2[j])) {
      if (count == k - 1) {
        /*@ assert i < m; */
        /*@ assert arr1[i] != -1; */
        return arr1[i];
      }
      i++;
    } else {
      /*@ assert j < n; */
      if (count == k - 1) {
        /*@ assert arr2[j] != -1; */
        return arr2[j];
      }
      j++;
    }
  }

  return -1;
}
