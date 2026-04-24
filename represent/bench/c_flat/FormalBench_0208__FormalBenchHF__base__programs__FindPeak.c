int findPeak(int * arr, int arr_len, int n);

int findPeak(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
}
