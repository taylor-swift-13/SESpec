int sumOfSubarrayProd(int * arr, int arr_len, int n);

int sumOfSubarrayProd(int * arr, int arr_len, int n) {

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}
