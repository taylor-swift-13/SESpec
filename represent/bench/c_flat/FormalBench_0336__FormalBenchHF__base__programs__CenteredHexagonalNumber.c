int centeredHexagonalNumber(int n);

int centeredHexagonalNumber(int n) {

        int r = 1;
        while (n > 0) {
            n--;
            r += 6 * n;
        }
        return r;
}
