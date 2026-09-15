class SVCOMP_linear_0143__227 {
    /*@ public normal_behavior
      @   ensures true;
      @*/
    static void foo227() {

        int x;
        int y = 0; // initialized to avoid Java definite-assignment error

        x = 0;

        //@ maintaining x % 5 == 0;
        //@ maintaining true;
        while (x < 99) {
            if (y % 2 == 0)
                x += 10;
            else
                x -= 5;
        }

    }
}