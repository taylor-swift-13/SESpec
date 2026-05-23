int foo1(int m, int n);


int foo1(int m, int n) {

        if (n == 0) {
            return m;
        }
        if (n > 0) {
            return foo1(m + 1, n - 1);
        } else {
            return foo1(m - 1, n + 1);
        }
}