class Lcm {

    //@ requires a > 0 && b > 0;
    //@ ensures \result > 0;
    //@ ensures \result % a == 0 && \result % b == 0;
    //@ ensures (\forall int k; k > 0 && k % a == 0 && k % b == 0; \result <= k);
    public static int lcm(int a, int b) {
        int gcd = gcd(a, b);
        //@ assert gcd > 0;
        return (a / gcd) * b; // Avoids overflow by dividing first
    }

    //@ requires x > 0 && y > 0;
    //@ ensures \result >= 0;  
 
    //@ ensures (\forall int k; k > 0 && x % k == 0 && y % k == 0; k <= \result);
    private static int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}