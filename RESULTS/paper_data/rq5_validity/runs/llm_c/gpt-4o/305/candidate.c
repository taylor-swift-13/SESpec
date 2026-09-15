/*@
    requires \valid(arr + (0..arr_len-1));
    requires n > 0 && n <= arr_len;
    ensures 0 <= \result < n;
    ensures \forall integer i; 0 <= i < \result ==> arr[i] <= arr[\result];
    ensures \forall integer i; \result < i < n ==> arr[i] <= arr[\result];
    assigns \nothing;
*/
int findPeak(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        /*@
        loop invariant 0 <= left <= right < n;
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
