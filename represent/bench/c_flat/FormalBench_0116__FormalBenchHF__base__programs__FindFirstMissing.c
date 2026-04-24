int findFirstMissing(int * array, int array_len, int start, int end);

int findFirstMissing(int * array, int array_len, int start, int end) {

        int min = start;
        int max = end;
        int mid;

        while (min <= max) {
            mid = (min + max) / 2;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return min;
}
