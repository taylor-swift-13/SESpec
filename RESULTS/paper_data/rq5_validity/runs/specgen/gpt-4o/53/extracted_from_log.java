class SVCOMP_linear_0143__227 {
    //@ ensures true;
    static void foo227() {

        int x;
        int y = 0; // Initialize y to avoid uninitialized variable error

        x = 0;

 
        //@ maintaining x >= 0;
        //@ decreases 99 - x;
        while (x < 99) {
            if (y % 2 == 0)
                x += 10;
            else
                x -= 5;
        }
    }
}