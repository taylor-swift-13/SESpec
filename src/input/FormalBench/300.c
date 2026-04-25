int foo300(int n, int m);

int foo300(int n, int m) {

        for (int i = n; i >= 0; i--) {
            if (i % m == 0) {
                return i;
            }
        }
        return -1;
}
