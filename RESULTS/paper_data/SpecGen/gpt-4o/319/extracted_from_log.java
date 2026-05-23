class Lcm {

    //@ requires n > 0 && y > 0;
    //@ ensures \result > 0;
    //@ ensures \result % n == 0 && \result % y == 0;
    public static int lcm(int n, int y) {
        int gcd = gcd(n, y);
 
        int lcm = (n / gcd) * y;
        //@ assert lcm > 0;
        return lcm;
    }

    //@ requires a > 0 && b > 0;
 
 
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}