/*@
    requires \valid_read(arr+(0..arr_len-1));
    requires n > 0 && n <= arr_len;
    requires \forall integer i; 0 <= i < n-1 ==> arr[i] <= arr[i+1];
    ensures \result == -1 || (0 <= \result < n && arr[\result] == x);
    ensures \result != -1 ==> (\forall integer i; 0 <= i < \result ==> arr[i] != x);
    assigns \nothing;
*/
int first(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        /*@
            loop invariant 0 <= low && low <= n;
            loop invariant -1 <= high && high < n;
            loop invariant -1 <= result < n;
            loop invariant \forall integer i; 0 <= i < low ==> arr[i] != x;
            loop invariant \forall integer i; high < i < n ==> arr[i] != x;
            loop assigns low, high, result;
            loop variant high - low + 1;
        */
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
}
