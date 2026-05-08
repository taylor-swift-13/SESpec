int foo70(int * arr, int arr_len, int n);

int foo70(int * arr, int arr_len, int n) {

        int count = 0;
        int i = 0;
        int j = 1;

        while (i < n && j < n) {
            if (arr[i] == arr[j]) {
                i++;
                j++;
                count++;
            } else if (arr[i] > arr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return count;
}
