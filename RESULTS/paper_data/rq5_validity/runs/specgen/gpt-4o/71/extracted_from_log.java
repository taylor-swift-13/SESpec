class SVCOMP_linear_0234__309 {
    static void foo309(int n) {

        int j;
        int i;
        int k;
        int v4;
        int v3;
        int l;

        i = 0;
        k = 0;
        j = 0;
        l = 0;
        v4 = 0;
        v3 = 0;

 
 
 
 
 
 
        //@ decreases n - l;
        while (l < n) {
            if ((l % 5) == 0) {
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

    /*@
      ensures v3 == (\sum int x; 0 <= x && x < n && x % 5 == 0; 1);
      ensures v4 == (\sum int x; 0 <= x && x < n && x % 5 != 0 && x % 4 == 0; 1);
      ensures i == (\sum int x; 0 <= x && x < n && x % 5 != 0 && x % 4 != 0 && x % 3 == 0; 1);
      ensures j == (\sum int x; 0 <= x && x < n && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 == 0; 1);
      ensures k == (\sum int x; 0 <= x && x < n && x % 5 != 0 && x % 4 != 0 && x % 3 != 0 && x % 2 != 0; 1);
    @*/
    public static void verifySpecifications(int n, int v3, int v4, int i, int j, int k) {
        // This method is a placeholder for verification purposes.
        // It does not contain any implementation but serves as a container for the specifications.
    }
}