class Last {

    //@ requires args != null; // The array must not be null
    //@ requires 0 <= y && y <= args.length; // y must be within the bounds of the array
    //@ requires (\forall int j; 0 <= j && j < y - 1; args[j] <= args[j + 1]); // The array must be sorted
    //@ ensures \result == -1 || (0 <= \result && \result < y && args[\result] == x); // Result is valid or -1
    public static int last(int[] args, int x, int y) {
        int left = 0;
        int right = y - 1;
        int result = -1;

        //@ maintaining 0 <= left && left <= y && -1 <= right && right < y;
        //@ maintaining result == -1 || (0 <= result && result < y && args[result] == x);
        //@ decreases right - left + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (args[mid] == x) {
                result = mid;
                left = mid + 1;
            } else if (args[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}