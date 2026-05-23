class SVCOMP_linear_0086__176 {
    /*@ spec_public @*/ 
    static void foo176(int i, int j, int k) {
        //@ ensures true;

        int n;
        int b;

        n = 0;
        b = 1;

 
        //@ maintaining (b == 0 || b == 1);
        //@ decreases 2 * k - n;
        while(n < (2 * k)){
            n = n + 1;
            if(b == 1){
                b = 0;
                i = i + 1;
            }
            else{
                b = 1;
                j = j + 1;
            }
        }

    }
}