int getGcd(int * arr, int arr_len);

int getGcd(int * arr, int arr_len) {

        int result = 0;
        int min = arr[0];
        for (int i = 1; i < arr_len; i++) {
            if (arr[i] > min) {
                result = result > min ? result : min;
            } else {
                min = arr[i];
            }
        }
        return result;
}
