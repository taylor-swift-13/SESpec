int oddLengthSum(int * arr, int arr_len);

int oddLengthSum(int * arr, int arr_len) {

        int sum = 0;
        int l = arr_len;
        for (int i = 0; i < l; i++) {
            sum += ((((i + 1) * (l - i) + 1) / 2) * arr[i]);
        }
        return sum;
}
