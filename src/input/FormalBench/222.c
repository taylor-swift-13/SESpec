int foo222(int * array, int array_len);

int foo222(int * array, int array_len) {

        int max = 0;
        for (int i = 0; i < array_len; i++) {
            if (array[i] > 0 && array[i] > max) {
                max = array[i];
            }
        }
        return max;
}
