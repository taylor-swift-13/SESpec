class SVCOMP_linear_0237__311 {

    //@ requires n >= 0;
    //@ ensures true;
    static void foo311(int n) {

        int j;
        int i;
        int k;
        int v4;
        int v3;
        int v2;
        int v1;
        int l;

        i = 0;
        k = 0;
        j = 0;
        l = 0;
        v4 = 0;
        v3 = 0;
        v2 = 0;
        v1 = 0;

        //@ maintaining 0 <= l && l <= n;
        //@ maintaining i >= 0 && j >= 0 && k >= 0 && v1 >= 0 && v2 >= 0 && v3 >= 0 && v4 >= 0;
        //@ decreasing n - l;
        while (l < n) {
            if((l % 7) == 0){
                v1 = v1 + 1;
            }
            else if((l % 6) == 0){
                v2 = v2 + 1;
            }
            else if ((l % 5) == 0){
                v3 = v3 + 1;
            }
            else if ((l % 4) == 0) {
                v4 = v4 + 1;
            }
            else if((l % 3) == 0){
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