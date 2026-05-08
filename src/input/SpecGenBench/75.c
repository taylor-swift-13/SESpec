int foo75(int n);

int foo75(int n) {

        return n > 0 && (n & (n - 1)) == 0;
}
