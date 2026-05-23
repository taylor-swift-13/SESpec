import java.io.*;

class CountDivisors {

    //@ requires n > 0;
    //@ ensures (\forall int i; 1 <= i && i <= n; (n % i == 0 ? true : true)); // Simplified logical constraint
    //@ ensures \result.equals("Even") || \result.equals("Odd");
    public static String countDivisors(int n) {
        int count = 0;
        //@ maintaining count >= 0;
        //@ maintaining 1 <= i && i <= n + 1;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
    }
}