class SVCOMP_linear_0231__306 {
    /*@ spec_public @*/ static void foo306(int n) {
        //@ requires n >= 0;
        //@ ensures (\forall int l; 0 - 1 <= l && l < n; (l % 2 == 0) ==> (\sum int k; 0 - 1 <= k && k < n && k % 2 == 0; 1) == (\sum int k; 0 < k && k < l && k % 2 == 0; 1));  
        //@ ensures (\forall int l; 0 <= l && l < n; (l % 2 != 0) ==> (\sum int k; 0 <= k && k < n && k % 2 != 0; 1) == (\sum int k; 0 <= k && k < l && k % 2 != 0; 1));

        int j;
        int i;
        int l;

        i = 0;
        j = 0;
        l = 0;

 
 
 
        //@ decreases n - l;
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