class SVCOMP_linear_0099__188 {
    /*@ public normal_behavior
      @   ensures \result == 0;
      @*/
    static int unknown() {
        return 0;
    }

    /*@ public normal_behavior
      @   ensures true;
      @*/
    static void foo188() {

        int x;
        int y;
        int z;
        int w;

        x = 0;
        y = 0;
        z = 0;
        w = 0;

        /*@
          @ maintaining z == 10 * w;
          @ maintaining w >= 0;
          @ maintaining x >= 0;
          @*/
        while(unknown() != 0){
            if(x >= 4){
                x = x + 1;
                y = y + 2;

            }
            else if(y > 10 * w && z >= 100 * x){
                y = 0 - y;
            }
            else{
                x = x + 1;
                y = y + 100;
            }
            w = w + 1;
            z = z + 10;
        }

    }
}