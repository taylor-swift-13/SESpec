void foo20(int *b, int b_len, int iBegin, int iEnd, int *a, int a_len);

void foo20(int *b, int b_len, int iBegin, int iEnd, int *a, int a_len) {
    int k = iBegin;

    while (iEnd - k > 0) {
        a[k] = b[k];
        k = k + 1;
    }
}
