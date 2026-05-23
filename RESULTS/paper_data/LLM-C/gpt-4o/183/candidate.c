/*@
    requires \valid(arr + (0..arr_len-1));
    requires n > 0 && n <= arr_len;
    ensures \result >= 0 && \result <= n;
    ensures \result == 0 ==> (\forall integer i; 0 <= i < n-1 ==> arr[i] <= arr[i+1]);
    ensures \result > 0 ==> (\forall integer i; 0 <= i < \result-1 ==> arr[i] <= arr[i+1]) &&
                            (\forall integer i; \result <= i < n-1 ==> arr[i] <= arr[i+1]) &&
                            arr[n-1] <= arr[0];
    assigns \nothing;
*/
int countRotation(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        /*@
            loop invariant 0 <= left <= right < n;
            loop invariant \forall integer i; 0 <= i < left ==> arr[i] <= arr[i+1];
            loop invariant \forall integer i; right < i < n-1 ==> arr[i] <= arr[i+1];
            loop assigns left, right;
            loop variant right - left;
        */
        while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left + 1;
}
