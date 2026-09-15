class NumberOfCuts {
    //@ requires true;
    //@ assignable \nothing;
    //@ ensures (\old(n) == 1) ==> \result == 0;
    //@ ensures (\old(n) != 1 && \old(n) % 2 == 0) ==> \result == \old(n) / 2;
    //@ ensures (\old(n) != 1 && \old(n) % 2 != 0) ==> \result == \old(n);
    public int numberOfCuts(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return n / 2;
        }
        return n;
    }
}