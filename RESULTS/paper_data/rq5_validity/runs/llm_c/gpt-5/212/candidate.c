int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

/*@ predicate sorted(int *a, integer n) =
      \forall integer k; 0 <= k < n-1 ==> a[k] <= a[k+1];

    predicate equal_except_index(int *a, integer n1, int *b, integer n2, integer r) =
      n1 == n2 + 1 && 0 <= r < n1 &&
      (\forall integer k; 0 <= k < r ==> a[k] == b[k]) &&
      (\forall integer k; r <= k < n2 ==> a[k+1] == b[k]);
*/

/*@ 
  requires arr1_len >= 0;
  requires arr2_len >= 0;
  requires arr1_len == 0 || \valid_read(arr1 + (0 .. arr1_len-1));
  requires arr2_len == 0 || \valid_read(arr2 + (0 .. arr2_len-1));
  requires sorted(arr1, arr1_len);
  requires sorted(arr2, arr2_len);
  requires (arr1_len == arr2_len + 1 && (\exists integer r1; equal_except_index(arr1, arr1_len, arr2, arr2_len, r1))) ||
           (arr2_len == arr1_len + 1 && (\exists integer r2; equal_except_index(arr2, arr2_len, arr1, arr1_len, r2)));

  assigns \nothing;

  behavior arr1_has_extra;
    assumes arr1_len == arr2_len + 1 && (\exists integer r1; equal_except_index(arr1, arr1_len, arr2, arr2_len, r1));
    ensures equal_except_index(arr1, arr1_len, arr2, arr2_len, \result);

  behavior arr2_has_extra;
    assumes arr2_len == arr1_len + 1 && (\exists integer r2; equal_except_index(arr2, arr2_len, arr1, arr1_len, r2));
    ensures equal_except_index(arr2, arr2_len, arr1, arr1_len, \result);

  disjoint behaviors arr1_has_extra, arr2_has_extra;

  ensures 0 <= \result < (arr1_len > arr2_len ? arr1_len : arr2_len);
*/
int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        /*@
          loop invariant 0 <= i <= arr1_len;
          loop invariant 0 <= j <= arr2_len;
          loop assigns i, j;
          loop variant (arr1_len - i) + (arr2_len - j);
        */
        while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}
