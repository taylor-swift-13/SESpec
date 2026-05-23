import java.io.*;

class CountDivisors {

    /*@ requires num > 0;
      @ ensures \result.equals("Even") <==> (\sum int i; 1 <= i && i <= num; (num % i == 0 ? 1 : 0)) % 2 == 0;
      @ ensures \result.equals("Odd") <==> (\sum int i; 1 <= i && i <= num; (num % i == 0 ? 1 : 0)) % 2 != 0;
      @*/
    public static String countDivisors(int num) {
        int count = 0;
        /*@ maintaining 1 <= i && i <= num + 1;
          @ maintaining count == (\sum int j; 1 <= j && j < i; (num % j == 0 ? 1 : 0));
          @ decreases num - i + 1;
          @*/
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
            }
        }
        //@ assert count == (\sum int i; 1 <= i && i <= num; (num % i == 0 ? 1 : 0));
        return (count % 2 == 0) ? "Even" : "Odd";
    }
}