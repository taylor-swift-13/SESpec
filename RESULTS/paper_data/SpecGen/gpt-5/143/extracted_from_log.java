class PassPillow {
    /*@
      @ public normal_behavior
      @   requires n >= 2;
      @   assignable \nothing;
      @   ensures \result == (time < n ? time + 1 : n * 2 - time - 1);
      @*/
    public int passPillow(int n, int time) {
        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
    }
}