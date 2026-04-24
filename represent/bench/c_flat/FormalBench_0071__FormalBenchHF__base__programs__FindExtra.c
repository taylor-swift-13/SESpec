int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n);

int findExtra(int * arr1, int arr1_len, int * arr2, int arr2_len, int n) {

        int i = 0;
        int j = 0;
        while (i < arr1_len && j < arr2_len) {
            if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr1[i] > arr2[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return i < arr1_len ? i : j;
}
