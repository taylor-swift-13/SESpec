class FindMaxVal {

    //@ requires value >= 0 && k > 0 && 0 <= z && z < k;
    //@ ensures \result + 1 >= 0;  
    //@ ensures (\forall int c; 1 <= c && c <= value; c % k != z) ==> \result == 0;
    //@ ensures \result > 0 ==> (\result % k == z && (\forall int c; 1 <= c && c <= value; (c % k == z) ==> \result >= c));
    public static int findMaxVal(int value, int k, int z) {
        int result = 0;
        for (int c = 1; c <= value; c++) {
            if ((c % k) == z) {
                result = c;
            }
        }
        return result;
    }
}
