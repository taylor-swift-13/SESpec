int leftInsertion(int * a, int a_len, int x);

int leftInsertion(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
}
