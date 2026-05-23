class SVCOMP_linear_0231__306 {
    /*@ ensures true; @*/
    static void foo306(int n) {

        int j;
        int i;
        int l;

        i = 0;
        j = 0;
        l = 0;

 
 
 
 
          @*/
        while (l < n) {
            if ((l % 2) == 0) {
                i = i + 1;
            } else {
                j = j + 1;
            }
            l = l + 1;
        }

    }
}