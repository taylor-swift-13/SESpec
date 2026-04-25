int foo154(int * arr, int arr_len, int n);

int foo154(int * arr, int arr_len, int n) {

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] % 2 == 0) {
                    count += arr[i];
                }
            }
        }
        return count;
}
