class DigitRoot {
 
 
    public int digitRoot(int num) {
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
