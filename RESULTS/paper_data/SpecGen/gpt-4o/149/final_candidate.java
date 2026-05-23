class PrimeCheck {

    //@ requires a > 1;
 
    public boolean isPrime(int a) {
        int i = 2;
        int mid = a / 2;

        //@ maintaining 2 <= i && i <= mid + 1;
 
        //@ decreases mid - i + 1;
        while (i <= mid) {
            if (a % i == 0)
                return false;
            i++;
        }
        return true;
    }
}
