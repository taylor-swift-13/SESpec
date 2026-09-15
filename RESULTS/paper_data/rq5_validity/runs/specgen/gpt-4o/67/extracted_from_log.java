class SVCOMP_linear_0225__300 {
    //@ requires n >= 0;
    //@ ensures true; // No postcondition can directly reference local variables like `j` and `k`.
    static void foo300(int n) {
        int i;
        int k;
        int j;

        i = 0;
        j = 0;
        k = 0;

 
        //@ maintaining j >= 0 && k >= 0;
        //@ maintaining (\exists int m; 0 <= m && m <= i; (m % 2 != 0) ==> j == 3 * ((m + 1) / 2));  
        //@ maintaining (\exists int m; 0 <= m && m <= i; (m % 2 == 0) ==> k == 3 * (m / 2));  
        //@ decreases n - i;
        while (i < n) {
            i = i + 3;
            if ((i % 2) != 0) {
                j = j + 3;
            } else {
                k = k + 3;
            }
        }
    }
}