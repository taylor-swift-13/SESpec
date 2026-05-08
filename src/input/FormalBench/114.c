int foo114(int * arr, int arr_len, int n, int sum);

int foo114(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}
