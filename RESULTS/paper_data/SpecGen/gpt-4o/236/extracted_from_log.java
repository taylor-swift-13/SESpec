class Last {

    //@ requires arr != null && arr.length > 0;
    //@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]); // Array is sorted
    //@ requires 0 <= n && n <= arr.length; // Valid range for n
    //@ ensures \result == -1 || (0 <= \result && \result < n && arr[\result] == x); // Result is valid or -1
    public static int last(int[] arr, int x, int n) {
        int low = 0;
        int high = n - 1;
        int result = -1;

        //@ maintaining 0 <= low && low <= high + 1 && high < n; // Valid bounds
        //@ maintaining result == -1 || (0 <= result && result < n && arr[result] == x); // Result validity
        //@ decreases high - low + 1; // Loop termination
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                result = mid;
                low = mid + 1; // Search to the right
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
}