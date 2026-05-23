class Last {

    //@ requires args != null && args.length > 0;
    //@ requires 0 <= y && y <= args.length;
    //@ requires (\forall int i; 0 <= i && i < y-1; args[i] <= args[i+1]); // Array is sorted
    //@ ensures (\result == -1) ==> (\forall int i; 0 <= i && i < y; args[i] != x); // If x is not in the array, return -1
    //@ ensures (\result >= 0 && \result < y) ==> (args[\result] == x && (\result == y-1 || args[\result+1] != x)); // Last occurrence
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
                result = mid; // Update result to current index
                left = mid + 1; // Move right to find the last occurrence
            } else if (args[mid] < x) {
                left = mid + 1; // Move right
            } else {
                right = mid - 1; // Move left
            }
        }

        return result;
    }
}