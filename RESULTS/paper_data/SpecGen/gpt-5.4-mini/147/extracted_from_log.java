class PowerOfThree {
 
    public boolean isPowerOfThree(int n) {
        int temp = n;
 
        //@ maintaining temp + 1 >= 0 || temp == n;  
 
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        return temp == 1;
    }
}