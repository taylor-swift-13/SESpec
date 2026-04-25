int foo44(int * bits, int bits_len);

int foo44(int * bits, int bits_len) {

        int n = bits_len, i = 0;
        while (i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
}
