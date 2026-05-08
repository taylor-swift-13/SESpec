int foo312(int n, int k);

int foo312(int n, int k) {

        int res = 1;
        int i = 1;
        while (i <= k) {
            res *= (n - i + 1);
            i++;
        }
        return res;
}
