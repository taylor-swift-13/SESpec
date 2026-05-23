class PassPillowBranch {
    /*@ requires n > 1 && time >= 0;
      @ ensures time == (\old(time) % (n - 1)) * 2;
      @ ensures (time < n ==> \result == time + 1) &&
      @         (time >= n ==> \result == n * 2 - time - 1);
      @ ensures 1 <= \result && \result <= n;
      @*/
    /*@ spec_public @*/ public int passPillow(int n, int time) {
        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
    }
}