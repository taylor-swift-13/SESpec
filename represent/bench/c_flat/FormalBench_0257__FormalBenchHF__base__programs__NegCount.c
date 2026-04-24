int negCount(int * array, int array_len);

int negCount(int * array, int array_len) {

        int count = 0;
        for (int i = 0; i < array_len; i++) {
            if (array[i] < 0) {
                count++;
            }
        }
        return count;
}
