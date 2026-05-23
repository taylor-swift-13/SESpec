class SVCOMP_linear_0232__307 {
/*@ 
  @ requires n >= 0;
  @ assignable \nothing;
  @ ensures true;
  @*/
  static void foo307(int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    /*@
      loop_invariant 0 <= l && l <= n;
      loop_invariant 0 <= i && 0 <= j && 0 <= k;
      loop_invariant i + j + k == l;
      decreases n - l;
    @*/
    while (l < n) {
      if ((l % 3) == 0) {
        i = i + 1;
      } else if ((l % 2) == 0) {
        j = j + 1;
      } else {
        k = k + 1;
      }
      l = l + 1;
    }
  }
}