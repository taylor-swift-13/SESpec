int findKProduct(int * * testArray, int testArray_len, int testArray_rows, int testArray_cols, int k);

int findKProduct(int * * testArray, int testArray_len, int testArray_rows, int testArray_cols, int k) {

        int product = 1;
        int n = testArray_len;
        for (int i = 0; i < n; i++) {
            product *= testArray[i][k];
        }
        return product;
}
