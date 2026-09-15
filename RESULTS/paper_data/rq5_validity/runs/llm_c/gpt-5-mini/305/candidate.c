int findPeak(int * arr, int arr_len, int n);

/*@
    requires arr != \null;
    requires arr_len >= n;
    requires n >= 1;
    requires \valid(arr + (0 .. arr_len-1));
    assigns \nothing;
    ensures 0 <= \result < n;
    ensures (\result == 0 || arr[\result] >= arr[\result-1]) &&
            (\result == n-1 || arr[\result] >= arr[\result+1]);
*/
int findPeak(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        /*@
            loop invariant 0 <= left <= right < n;
            loop invariant \exists integer k; left <= k <= right &&
                ((k == 0) || arr[k] >= arr[k-1]) &&
                ((k == n-1) || arr[k] >= arr[k+1]);
            loop assigns left, right;
            loop variant right - left;
        */
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
}
