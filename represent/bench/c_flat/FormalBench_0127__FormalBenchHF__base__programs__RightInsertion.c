int rightInsertion(int * a, int a_len, int x);

int rightInsertion(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}
