import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class AverageEven {

    /*@ spec_public @*/
    /*@ 
      @ requires n >= 2;
      @ // The sum of all even numbers in 1..n equals result * (number of such even numbers)
      @ ensures (\sum int i; 1 <= i && i <= n && i % 2 == 0; i) 
      @            == \result * (\sum int i; 1 <= i && i <= n && i % 2 == 0; 1);
      @ // The result is between the smallest and largest even in the range (at least 2 and at most n)
      @ ensures \result >= 2 && \result <= n;
      @*/
    public static int averageEven(int n) {
        int sum = 0;
        int count = 0;
        /*@ 
          @ maintaining 1 <= i && i <= n + 1;
          @ maintaining sum == (\sum int j; 1 <= j && j < i && j % 2 == 0; j);
          @ maintaining count == (\sum int j; 1 <= j && j < i && j % 2 == 0; 1);
          @ decreases n - i + 1;
          @*/
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum += i;
                count++;
            }
        }
        return sum / count;
    }
}