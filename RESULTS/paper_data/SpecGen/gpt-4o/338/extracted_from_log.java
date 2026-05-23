import java.io.*;

class MaxPrimeFactors {

    //@ requires num > 1;
 
    //@ ensures (\forall int q; 2 <= q && q <= num; (num % q == 0 ==> q <= \result));
    public static int maxPrimeFactors(int num) {
        int result = 0;
        for (int j = 2; j <= num; j++) {
            while (num % j == 0) {
                result = j;
                num /= j;
            }
        }
        return result;
    }
}