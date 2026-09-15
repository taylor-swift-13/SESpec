int firstMissingPositive(int * arr, int arr_len, int n);

int firstMissingPositive(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
        loop invariant \forall integer k; i <= k < n ==> arr[k] != 0;
        loop assigns i;
        loop assigns arr[0..n-1];
        */
        while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}
