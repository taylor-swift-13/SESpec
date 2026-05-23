class NumberOfCutsSeq {
    /*@ public normal_behavior
      @ ensures \result == ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
 
      @ assignable \nothing;
      @*/
    public int numberOfCuts(int n) {
        return ((n == 1) ? 0 : ((n % 2 == 0) ? (n / 2) : n));
    }
}
