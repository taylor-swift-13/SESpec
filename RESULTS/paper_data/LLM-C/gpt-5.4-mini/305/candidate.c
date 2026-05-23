/*@
    requires n > 0;
    requires arr_len >= n;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result < n;
*/
int findPeak(int * arr, int arr_len, int n);

 /*@
    requires n > 0;
    requires arr_len >= n;
    requires \valid_read(arr + (0 .. arr_len - 1));
    assigns \nothing;
    ensures 0 <= \result < n;
*/
int findPeak(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        /*@
            loop invariant 0 <= left <= right < n;
            loop invariant \valid_read(arr + (0 .. arr_len - 1));
            loop assigns left, right, mid;
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
