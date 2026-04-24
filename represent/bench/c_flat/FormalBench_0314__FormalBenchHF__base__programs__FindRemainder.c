int findRemainder(int * arr, int arr_len, int lens, int n);

int findRemainder(int * arr, int arr_len, int lens, int n) {

        long product = 1;
        for (int i = 0; i < lens; i++) {
            product *= arr[i];
        }
        return (int)(product % n);
}
