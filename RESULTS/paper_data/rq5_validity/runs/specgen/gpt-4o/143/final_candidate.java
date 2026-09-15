class PassPillow {
    //@ requires n > 1 && time >= 0;
    //@ ensures 1 <= \result && \result <= n;
    public int passPillow(int n, int time) {
        time %= (n - 1) * 2;
        //@ assert 0 <= time && time < (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
    }
}