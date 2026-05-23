class RightInsertion {

    //@ requires a.length > 0;
    //@ requires (\forall int i; 0 <= i && i < a.length - 1; a[i] <= a[i + 1]);
    //@ ensures 0 <= \result && \result <= a.length;
    public static int rightInsertion(int[] a, int x) {
        int low = 0;
        int high = a.length;

        //@ maintaining 0 <= low && low <= high && high <= a.length;
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            if (a[mid] < x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}