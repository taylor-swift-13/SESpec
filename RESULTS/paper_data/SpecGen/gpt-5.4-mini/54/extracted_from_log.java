class SVCOMP_linear_0144__228 {
    static void foo228() {

        int x;
        int y = 0;

        x = 0;

        /*@ maintaining x - 1 <= 99;  
          @ decreases 99 - x;
          @*/
        while (x < 99) {
            if (y % 2 == 0) {
                x = x + 2;
            } else {
                x = x + 1;
            }
        }

    }
}