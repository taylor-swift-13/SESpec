class DigitRoot {
    //@ requires num >= 0;
    //@ ensures \result >= 0 && \result < 10;
    //@ ensures (\exists int k; k >= 0; num == k * 9 + \result);
    public int digitRoot(int num) {
        //@ maintaining num >= 0;
        //@ maintaining num + 1 >= 10 ==> (\exists int k; k + 1 >= 0; num == k * 9 + (\sum int i; 0 - 1 <= i && i <= \old(num); i % 10));  
 
        while (num >= 10) {
            int sum = 0;
            //@ maintaining sum >= 0;
            //@ maintaining num >= 0;
 
            //@ decreases num;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
}
