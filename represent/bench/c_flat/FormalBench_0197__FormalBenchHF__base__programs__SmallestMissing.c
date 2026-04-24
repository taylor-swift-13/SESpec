int smallestMissing(int * a, int a_len, int leftElement, int rightElement);

int smallestMissing(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}
