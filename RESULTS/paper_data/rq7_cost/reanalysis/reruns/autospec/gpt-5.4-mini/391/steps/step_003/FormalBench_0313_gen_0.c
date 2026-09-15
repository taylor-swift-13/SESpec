int nextPerfectSquare(int n);

int nextPerfectSquare(int n) {

        int i = 1;
        int square = 1;
        /*@
        loop invariant square == (i-1)*(i-1);
        loop invariant 1 <= i;
        loop invariant square >= 1;
        loop invariant square <= n + i*i;
        loop invariant square <= n + 2*i;
        loop invariant square == (i-1)*(i-1);
        loop invariant square == (i-1)*(i-1) || square <= n;
        loop invariant square == (i - 1) * (i - 1);
        loop invariant square <= n || square == i*i;
        loop invariant square <= n || i == 1;
        loop invariant square <= n + i*i;
        loop invariant square <= n + 2*i;
        loop invariant square <= n + 1;
        loop invariant square <= n + 1 || i == 1;
        loop invariant square <= i*i;
        loop invariant square % 2 == 0 || square % 2 == 1;
        loop invariant i*i > square || square <= n;
        loop invariant \forall integer k; 1 <= k < i ==> k*k <= square;
        loop invariant \forall integer k; 1 <= k < i ==> k*k <= n;
        loop invariant \forall integer k; 1 <= k < i ==> k*k <= n + 1;
        loop invariant \forall integer k; 1 <= k < i ==> k * k <= n;
        loop invariant \forall integer k; 0 < k < i ==> k * k <= n;
        loop invariant 1 <= square;
        loop invariant 1 <= i;
        loop invariant 0 <= square;
        loop invariant 0 < i;
        loop invariant (i-1)*(i-1) <= square;
        loop assigns square;
        loop assigns i;
        */
        while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}
