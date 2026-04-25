int foo333(int n);

int foo333(int n) {

        int i = 1;
        while ((n & 1) == 0) {
            n >>= 1;
            i++;
        }
        return i;
}
