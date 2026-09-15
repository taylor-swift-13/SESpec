class FindExtra {

    //@ requires args != null && arr != null;
    //@ requires args.length == arr.length + 1; // args has exactly one extra element
    //@ requires (\forall int i; 0 <= i && i < args.length - 1; args[i] <= args[i + 1]);
    //@ requires (\forall int i; 0 <= i && i < arr.length - 1; arr[i] <= arr[i + 1]);
    //@ ensures 0 <= \result && \result < args.length;
    //@ ensures (\forall int i; 0 <= i && i < arr.length; i < \result ==> args[i] == arr[i]);
    //@ ensures (\forall int i; 0 <= i && i < arr.length; i >= \result ==> args[i + 1] == arr[i]);
    public static int findExtra(int[] args, int[] arr) {
        int low = 0, high = args.length - 1;

        //@ maintaining 0 <= low && low <= high && high < args.length;
        //@ maintaining (\forall int i; 0 <= i && i < low; args[i] == arr[i]);
        //@ maintaining (\forall int i; high < i && i < args.length; args[i] == arr[i - 1]);
        //@ decreases high - low;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (args[mid] == arr[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low; // The index of the extra element
    }
}