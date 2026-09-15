
/*@
requires n >= 0;
requires \valid_read(arr + (0 .. n - 1));
requires \forall integer p, q; 0 <= p <= q < n ==> arr[p] <= arr[q];
assigns \nothing;
ensures \result != -1 ==> 0 <= \result < n;
ensures \result != -1 ==> arr[\result] == x;
ensures \result != -1 ==> \exists integer k; 0 <= k < n && arr[k] == x;
*/
int foo236(int * arr, int arr_len, int x, int n) {

    int i = 0;
    int j = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant -1 <= j < n;
      loop invariant i <= j + 1;
      loop invariant result == -1 || (0 <= result < n && arr[result] == x);
      loop invariant result == -1 ==> \forall integer k; 0 <= k < i ==> arr[k] < x;
      loop invariant result == -1 ==> \forall integer k; j < k < n ==> arr[k] > x;
      loop assigns i, j, result;
    */
    while (i <= j && result == -1) {
        int mid = (i + j) / 2;
        /*@ assert 0 <= mid < n; */
        if (arr[mid] == x) {
            result = mid;
        } else if (arr[mid] < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }

    return result;
}
