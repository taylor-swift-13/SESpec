int sumColumn(int * * array, int array_len, int array_rows, int array_cols, int c);

int sumColumn(int * * array, int array_len, int array_rows, int array_cols, int c) {

        int sum = 0;
        for (int i = 0; i < array_len; i++) {
            sum += array[i][c];
        }
        return sum;
}
