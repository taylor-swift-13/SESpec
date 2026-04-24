int modularInverse(int * arr, int arr_len, int n, int p);

int modularInverse(int * arr, int arr_len, int n, int p) {

        int count = 0;

        for (int i = 0; i < n; i++) {
            int x = (arr[i] * arr[i]) % p;
            if (x == 1) {
                count++;
            }
        }
        return count;
}
