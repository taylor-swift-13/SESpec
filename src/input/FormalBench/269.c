int foo269(int n);

int foo269(int n) {

        if (n == 0) {
            return 1;
        }
        int i = 1;
        while (i < n) {
            i = i << 1;
        }
        return i;
}
