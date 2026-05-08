int foo2(int m, int n);

int foo2(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo2(m + 1, n - 1);
        } else {
            return foo2(m - 1, n + 1);
        }
}
