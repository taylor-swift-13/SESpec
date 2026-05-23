class FindExtra {

    //@ requires args != null && arr != null;
    //@ requires args.length == arr.length + 1; // args has one extra element
    //@ requires (\forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1]); // args is sorted
    //@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]); // arr is sorted
    //@ ensures 0 <= \result && \result < args.length; // result is a valid index
    //@ ensures (\forall int i; 0 <= i && i < arr.length; i != \result ==> args[i] == arr[i]); // all elements except the extra one match
    //@ ensures args[\result] != arr[\result]; // the extra element is at the result index
    public static int findExtra(int[] args, int[] arr) {
        int low = 0, high = args.length - 1;

        //@ maintaining 0 <= low && low <= high && high < args.length;
        //@ maintaining (\forall int i; 0 <= i && i < low; args[i] == arr[i]);
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid < arr.length && args[mid] == arr[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        //@ assert low == high;
        return low;
    }
}