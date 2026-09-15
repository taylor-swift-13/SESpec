class PassPillowBranch {
    /*@ 
      @ requires n >= 2;
      @ requires time >= 0;
      @ ensures \result >= 1 && \result <= n;
      @ ensures (((time % (n-1)) * 2) < n) ==> \result == ((time % (n-1)) * 2) + 1;
      @ ensures (((time % (n-1)) * 2) >= n) ==> \result == 2*n - ((time % (n-1)) * 2) - 1;
      @*/
    public /*@ spec_public @*/ int passPillow(int n, int time) {
        time = time % (n - 1) * 2;
        if (time < n) {
            return time + 1;
        }
        return n * 2 - time - 1;
    }
}