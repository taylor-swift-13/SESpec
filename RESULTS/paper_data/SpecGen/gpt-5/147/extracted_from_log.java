class PowerOfThree {
    //@ ensures n == 1 ==> \result;
    //@ ensures n == 0 ==> !\result;
    //@ ensures (n != 1 && n % 3 != 0) ==> !\result;
    public boolean isPowerOfThree(int n) {
        int temp = n;
        //@ maintaining true;
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
    }
}