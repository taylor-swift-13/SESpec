class Sespec0032 {
    /*@ public normal_behavior
      @   ensures (i == 0.0) ==> \result == 0;
      @   ensures (i != 0.0) ==> \result == 1;
      @   assignable \nothing;
      @*/
    /*@ spec_public @*/
    static int foo32(double i) {
        if (i == 0.0) return 0;
        double j = 10.0 / i;
        return 1;
    }
}