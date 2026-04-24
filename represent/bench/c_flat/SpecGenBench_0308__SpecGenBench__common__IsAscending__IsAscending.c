int isAscending(int * arr, int arr_len);

int isAscending(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
        return 1;
}
