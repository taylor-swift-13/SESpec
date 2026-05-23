public class GCD {

    //@ requires num1 >= 0 && num2 >= 0;
    //@ ensures \result == -1 <==> (num1 == 0 && num2 == 0);
    //@ ensures \result == ((num1 > num2) ? num1 : num2) <==> (num1 == 0 || num2 == 0);
    //@ ensures \result > 0 ==> (num1 % \result == 0 && num2 % \result == 0);
    //@ ensures \result > 0 ==> (\forall int i; i > 0 && i < \result; (num1 % i == 0 && num2 % i == 0) ==> i <= \result);
    public static int gcd(int num1, int num2){
        int result = 1;
        num1 = (0 <= num1) ? num1 : -num1;
        num2 = (0 <= num2) ? num2 : -num2;

        if (num1 == 0 && num2 == 0) {
            return -1;
        }

        if (num1 == 0 || num2 == 0) {
            return (num1 > num2) ? num1 : num2;
        }

        //@ maintaining 1 <= i && i <= num1 + 1 && i <= num2 + 1;
        //@ maintaining (\forall int j; 1 <= j && j <= i; (num1 % j == 0 && num2 % j == 0) ==> j <= result);  
        //@ maintaining result > 0 ==> (num1 % result == 0 && num2 % result == 0);
        //@ decreases num1 + num2 - i;
        for (int i = 1; i <= num1 && i <= num2; i++) {
            if (num1 % i == 0 && num2 % i == 0) {
                result = i;
            }
        }
        return result;
    }
}
