class FindLastOccurrence {

    //@ requires a != null && a.length > 0;
    //@ requires (\forall int i; 0 <= i && i < a.length - 1; a[i] <= a[i + 1]); // Array must be sorted
    //@ ensures \result == -1 || (0 <= \result && \result < a.length); // Result is valid or -1
    //@ ensures (\result == -1) <==> (\forall int i; 0 <= i && i < a.length; a[i] != x); // -1 if x is not found
    //@ ensures (\result >= 0) ==> (a[\result] == x && (\result == a.length - 1 || a[\result + 1] != x)); // Last occurrence of x
    public static int findLastOccurrence(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;

        //@ maintaining 0 <= low && low <= high + 1 && high < a.length;
        //@ maintaining (\forall int i; 0 <= i && i < low; a[i] < x); // All elements before `low` are less than x
        //@ maintaining (\forall int i; high + 1 <= i && i < a.length; a[i] > x); // All elements after `high` are greater than x
        //@ decreases high - low + 1; // Loop progresses
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            if (a[mid] <= x) {
                low = mid + 1; // Move to the right half
            } else {
                high = mid - 1; // Move to the left half
            }
        }

        // Check if the element at `high` is the last occurrence of `x`
        if (high >= 0 && a[high] == x) {
            return high;
        }

        return -1; // x not found
    }
}