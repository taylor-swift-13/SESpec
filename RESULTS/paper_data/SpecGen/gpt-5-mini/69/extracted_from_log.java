class SVCOMP_linear_0232__307 {
    /*@ requires n >= 0;
      @ ensures i + j + k == n;
      @ ensures i == (\sum int t; 0 <= t && t < n; (t % 3 == 0 ? 1 : 0));
      @ ensures j == (\sum int t; 0 <= t && t < n; (t % 3 == 0 ? 0 : (t % 2 == 0 ? 1 : 0)));
      @ ensures k == (\sum int t; 0 <= t && t < n; ((t % 3 != 0 && t % 2 != 0) ? 1 : 0));
      @*/
    static void foo307(unsigned int n) {

    unsigned
    /*@ spec_public @*/ unsigned int j;
    /*@ spec_public @*/ unsigned int i;
    /*@ spec_public @*/ unsigned int k;
    /*@ spec_public @*/ unsigned int l;

    i = 0;
    k = 0;
    j = 0;
    l = 0;

    //@ maintaining 0 <= l && l <= n;
    //@ maintaining 0 <= i && 0 <= j && 0 <= k;
    //@ maintaining i + j + k == l;
    //@ maintaining i == (\sum int t; 0 <= t && t < l; (t % 3 == 0 ? 1 : 0));
    //@ maintaining j == (\sum int t; 0 <= t && t < l; (t % 3 == 0 ? 0 : (t % 2 == 0 ? 1 : 0)));
    //@ maintaining k == (\sum int t; 0 <= t && t < l; ((t % 3 != 0 && t % 2 != 0) ? 1 : 0));
    //@ decreases n - l;
    while (l < n) {
    if ((l % 3) == 0) {
    i = i + 1;
    }
    else if((l % 2) == 0){
    j = j + 1;
    }
    else{
    k = k + 1;
    }
    l = l + 1;
    }

    }
    }