/*@
    requires \valid_read(arr + (0..arr_len-1));
    requires arr_len > 0;
    requires n > 0 && n <= arr_len;
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < n && arr[\result] == x);
    ensures \result == -1 ==> \forall integer k; 0 <= k < n ==> arr[k] != x;
    ensures \result != -1 ==> \forall integer k; \result < k < n ==> arr[k] != x;
*/
int last(int * arr, int arr_len, int x, int n) {

        int i = 0;
        int j = n - 1;
        int result = -1;

        /*@
            loop invariant 0 <= i && i <= n;
            loop invariant -1 <= j && j < n;
            loop invariant result == -1 || (0 <= result < n && arr[result] == x);
            loop invariant \forall integer k; 0 <= k < i ==> arr[k] != x || result != -1;
            loop invariant \forall integer k; j < k < n ==> arr[k] != x;
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
