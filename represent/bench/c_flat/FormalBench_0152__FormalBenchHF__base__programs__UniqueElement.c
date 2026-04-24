const char * uniqueElement(int * arr, int arr_len, int n);

const char * uniqueElement(int * arr, int arr_len, int n) {

        if (n == 0) {
            return "NO";
        }

        int firstElement = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] != firstElement) {
                return "NO";
            }
        }
        return "YES";
}
