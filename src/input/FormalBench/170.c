int foo170(int * arr, int arr_len, int n);

int foo170(int * arr, int arr_len, int n) {

        int i = 0;
        while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
        return arr[n - 1];
}
