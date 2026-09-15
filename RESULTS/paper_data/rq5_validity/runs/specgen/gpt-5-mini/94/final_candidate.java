class CanWinNim {
    /*@ public normal_behavior
      @  requires n >= 0;
      @  ensures \result == (n % 4 != 0);
      @  assignable \nothing;
      @*/
    public boolean canWinNim(int n) {
        return n % 4 != 0;
    }
}