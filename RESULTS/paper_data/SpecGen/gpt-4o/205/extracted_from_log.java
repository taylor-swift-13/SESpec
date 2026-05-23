class FindExtra {

    //@ requires args != null && arr != null;
    //@ requires args.length == arr.length + 1; // args has one extra element compared to arr
    //@ requires (\forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1]); // args is sorted
    //@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]); // arr is sorted
    //@ ensures 0 <= \result && \result < args.length; // result is a valid index in args
    //@ ensures (\forall int i; 0 <= i && i < \result; args[i] == arr[i]); // elements before the extra are equal
    //@ ensures (\result == arr.length || args[\result] != arr[\result]); // result points to the extra element
    public static int findExtra(int[] args, int[] arr) {
        int left = 0, right = args.length - 1;

        //@ maintaining 0 <= left && left <= right && right < args.length;
        //@ decreases right - left;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid < arr.length && args[mid] == arr[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
}