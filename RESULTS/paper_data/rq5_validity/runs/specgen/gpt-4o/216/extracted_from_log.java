class Last {

    //@ requires array != null && array.length > 0;
    //@ requires 0 <= y && y <= array.length;
    //@ requires (\forall int i; 0 <= i && i < y - 1; array[i] <= array[i + 1]); // Array must be sorted
    //@ ensures (\result == -1) ==> (\forall int i; 0 <= i && i < y; array[i] != x); // x not found
    //@ ensures (\result != -1) ==> (array[\result] == x && (\forall int i; \result < i && i < y; array[i] != x)); // Last occurrence of x
    public static int last(int[] array, int x, int y) {
        int left = 0;
        int right = y - 1;
        int result = -1;

        //@ maintaining 0 <= left && left <= right + 1 && right < y;
        //@ maintaining (\forall int i; 0 <= i && i < left; array[i] != x); // x not found before left
        //@ maintaining (\forall int i; right < i && i < y; array[i] != x); // x not found after right
        //@ decreases right - left + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == x) {
                result = mid; // Update result to the current index
                left = mid + 1; // Move to the right to find the last occurrence
            } else if (array[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}