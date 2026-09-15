/*@
    requires \valid(arr + (0..arr_len-1));
    requires n > 0 && n <= arr_len;
    ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
    assigns \nothing;
*/
int findFixedPoint(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        /*@
            loop invariant 0 <= start && start <= end + 1 && end < n;
            loop invariant \forall integer i; 0 <= i < start ==> arr[i] != i;
            loop invariant \forall integer i; end + 1 <= i < n ==> arr[i] != i;
            loop assigns start, end;
            loop variant end - start + 1;
        */
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == mid) {
                return mid;
            } else if (arr[mid] < mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
}
