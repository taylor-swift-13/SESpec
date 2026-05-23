/*@
    requires arr_len > 0;
    requires 0 < n <= arr_len;
    requires \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
    ensures \result == -1 ==> (\forall integer i; 0 <= i < n ==> arr[i] != i);
*/
int findFixedPoint(int * arr, int arr_len, int n);

 /*@
    requires arr_len > 0;
    requires 0 < n <= arr_len;
    requires \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
    ensures \result == -1 ==> (\forall integer i; 0 <= i < n ==> arr[i] != i);
*/
int findFixedPoint(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        /*@
            loop invariant 0 <= start <= n;
            loop invariant -1 <= end < n;
            loop invariant start <= end + 1;
            loop invariant (\forall integer i; 0 <= i < start ==> arr[i] < i);
            loop invariant (\forall integer i; end < i < n ==> arr[i] > i);
            loop assigns start, end, mid;
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
