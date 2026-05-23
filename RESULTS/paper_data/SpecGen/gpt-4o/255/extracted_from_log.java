class LeftInsertion {

    //@ requires args != null && args.length >= 0;
    //@ requires (\forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1]); // Array must be sorted
    //@ ensures 0 <= \result && \result <= args.length;
    public static int leftInsertion(int[] args, int array) {
        int low = 0;
        int high = args.length;

        //@ maintaining 0 <= low && low <= high && high <= args.length;
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            if (args[mid] < array) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}