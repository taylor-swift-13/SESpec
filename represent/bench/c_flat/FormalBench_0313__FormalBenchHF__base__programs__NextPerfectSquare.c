int nextPerfectSquare(int n);

int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
