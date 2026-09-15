int firstMissingPositive(int * arr, int arr_len, int n);

int firstMissingPositive(int * arr, int arr_len, int n) {

        int i = 0;
        /*@
        loop invariant i == 0 || arr[i-1] == i;
        loop invariant \forall integer k; i <= k < n ==> arr[k] != k + 1;
        loop invariant \forall integer k; i <= k < n ==> arr[k] != k + 1 || arr[k] <= 0 || arr[k] > n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] >= 1 ==> arr[k] <= n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1 || arr[k] <= 0 || arr[k] > n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1 ==> arr[k] > 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1 ==> arr[k] != 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1 ==> arr[arr[k]-1] == arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != k + 1 || arr[k] <= 0 || arr[k] > n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != 0;
        loop invariant i <= n;
        loop invariant \forall integer k; i <= k < n ==> arr[k] != 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] == k + 1 || arr[k] <= 0 || arr[k] > n);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1);
        loop invariant 0 <= i;
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
        /*@
        loop invariant i <= n;
        loop invariant \forall integer k; i <= k < n ==> arr[k] != 0;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] == k + 1 || arr[k] <= 0 || arr[k] > n);
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] <= 0 || arr[k] > n || arr[k] == k + 1);
        loop invariant 0 <= i;
        loop assigns i;
        loop assigns arr[0..n-1];
        */
        for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
}
