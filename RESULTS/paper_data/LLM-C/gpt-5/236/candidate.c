int last(int * arr, int arr_len, int x, int n);

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires \valid_read(arr + (0 .. n - 1));
  requires \forall integer k1, k2; 0 <= k1 <= k2 < n ==> arr[k1] <= arr[k2];
  assigns \nothing;
  ensures (\forall integer i; 0 <= i < n ==> arr[i] != x) ==> \result == -1;
  ensures (\exists integer i; 0 <= i < n && arr[i] == x) ==> 
          (0 <= \result < n && arr[\result] == x &&
           (\forall integer k; \result < k < n ==> arr[k] != x));
*/
int last(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        /*@
          loop invariant 0 <= i <= n;
          loop invariant -1 <= j < n;
          loop invariant i <= j + 1;
          loop invariant (\forall integer k; 0 <= k < i ==> arr[k] <= x);
          loop invariant (\forall integer k; j < k < n ==> arr[k] > x);
          loop invariant result == -1 ==> (\forall integer k; 0 <= k < i ==> arr[k] != x);
          loop invariant result != -1 ==> (0 <= result < i && arr[result] == x &&
                                           (\forall integer k; result < k < i ==> arr[k] != x));
          loop assigns i, j, result;
          loop variant j - i + 1;
        */
        while (i <= j) {
            int mid = (i + j) / 2;
            if (arr[mid] == x) {
                result = mid;
                i = mid + 1;
            } else if (arr[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return result;
}
