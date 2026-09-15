int nextPerfectSquare(int n);

int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
        loop invariant i >= 1;
        loop invariant square == (i-1)*(i-1);
        loop invariant square >= 0;
        loop invariant square <= n + 2*i;
        loop assigns i;
        loop assigns square;
        */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
