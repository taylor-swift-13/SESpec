class First {

    //@ requires args != null; // The input array must not be null
    //@ requires 0 <= n && n <= args.length; // n must be within the bounds of the array
    //@ requires (\forall int i; 0 <= i && i < n - 1; args[i] <= args[i + 1]); // The array must be sorted in non-decreasing order
    //@ ensures \result == -1 || (0 <= \result && \result < n && args[\result] == array); // Result is either -1 or a valid index
    public static int first(int[] args, int array, int n) {
        int low = 0;
        int high = n - 1;
        int result = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (args[mid] == array) {
                result = mid;
                high = mid - 1; // Continue searching in the left half
            } else if (args[mid] < array) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
        return result;
    }
}