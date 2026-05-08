int getInvCount(int * arr, int arr_len, int n);

int getInvCount(int * arr, int arr_len, int n) {

        int invCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }
        return invCount;
}
