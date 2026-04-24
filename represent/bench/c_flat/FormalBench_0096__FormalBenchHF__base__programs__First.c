int first(int * arr, int arr_len, int x, int n);

int first(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
}
