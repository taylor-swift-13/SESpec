int foo29(int n, int m);

int foo29(int n, int m) {
    if (m < 0) {
        return foo29(n, -m);
    }
    if (m == 0) {
        return 0;
    }
    return n + foo29(n, m - 1);
}
