class Last {

    //@ requires arr != null;
    //@ requires 0 <= n && n <= arr.length;
    //@ requires (\forall int i; 0 <= i && i < n - 1; arr[i] <= arr[i + 1]);
    //@ ensures (\result == -1) <==> (\forall int i; 0 <= i && i < n; arr[i] != x);
    //@ ensures (\result != -1) ==> (0 <= \result && \result < n && arr[\result] == x);
    //@ ensures (\result != -1) ==> (\forall int i; \result < i && i < n; arr[i] != x);
    public static int last(int[] arr, int x, int n) {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        //@ maintaining 0 <= low && low <= n;
        //@ maintaining -1 <= high && high < n;
        //@ maintaining -1 <= ans && ans < n;
        //@ maintaining ans == -1 || arr[ans] == x;
        //@ decreases high - low + 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
}