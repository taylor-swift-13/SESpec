int foo155(int * arr, int arr_len, int n);

int foo155(int * arr, int arr_len, int n) {

        int sum = 0;
        for (int i = 0; i < arr_len; i++) {
            for (int j = i + 1; j < arr_len; j++) {
                sum += arr[i] ^ arr[j];
            }
        }
        return sum;
}
