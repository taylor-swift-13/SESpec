class SVCOMP_linear_0237__311 {
    /*@ spec_public @*/ static void foo311(int n) {
        /*@ spec_public @*/ int j;
        /*@ spec_public @*/ int i;
        /*@ spec_public @*/ int k;
        /*@ spec_public @*/ int v4;
        /*@ spec_public @*/ int v3;
        /*@ spec_public @*/ int v2;
        /*@ spec_public @*/ int v1;
        /*@ spec_public @*/ int l;

        i = 0;
        k = 0;
        j = 0;
        l = 0;
        v4 = 0;
        v3 = 0;
        v2 = 0;
        v1 = 0;

        //@ maintaining 0 <= l && l <= n;
        //@ maintaining v1 + v2 + v3 + v4 + i + j + k == l;
        //@ maintaining (\forall int x; 0 <= x && x < l; (x % 7 == 0 ==> v1 > 0) && (x % 6 == 0 && x % 7 != 0 ==> v2 > 0) && (x % 5 == 0 && x % 6 != 0 && x % 7 != 0 ==> v3 > 0) && (x % 4 == 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 ==> v4 > 0) && (x % 3 == 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 ==> i > 0) && (x % 2 == 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 ==> j > 0) && (x % 2 != 0 && x % 3 != 0 && x % 4 != 0 && x % 5 != 0 && x % 6 != 0 && x % 7 != 0 ==> k > 0));
        //@ decreases n - l;
        while (l < n) {
            if ((l % 7) == 0) {
                v1 = v1 + 1;
            } else if ((l % 6) == 0) {
                v2 = v2 + 1;
            } else if ((l % 5) == 0) {
                v3 = v3 + 1;
            } else if ((l % 4) == 0) {
                v4 = v4 + 1;
            } else if ((l % 3) == 0) {
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