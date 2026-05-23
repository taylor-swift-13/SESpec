import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class NcrModP {

    /*@ spec_public
      @ requires n >= 0 && r >= 0 && p > 0;
      @ ensures (n < r) ==> \result == 0;
      @ ensures (n >= r) ==> 0 <= \result && \result < p;
      @ // The following postcondition states that when n >= r the result is the binomial coefficient C(n,r) modulo p.
      @ // We express C(n,r) by the multiplicative formula C = \prod_{j=1..r} (n-j+1)/j.
      @ ensures (n >= r) ==> (\exists long C; C == (\product int j; 1 <= j && j <= r; (n - j + 1)) / (\product int j; 1 <= j && j <= r; j) && \result == (int)(C % p));
      @*/
    public static int ncrModP(int n, int r, int p) {
        if (n < r) {
            return 0;
        }

        int ncr = 1;
        /*@ 
          @ maintaining 1 <= i && i <= r+1;
          @ // Invariant: after (i-1) iterations, ncr equals the product_{j=1..i-1} (n-j+1)/j
          @ maintaining ncr == (\product int j; 1 <= j && j <= i-1; (n - j + 1)) / (\product int j; 1 <= j && j <= i-1; j);
          @ decreases r - i + 1;
          @*/
        for (int i = 1; i <= r; i++) {
            ncr = (ncr * (n - i + 1)) / i;
        }

        return ncr % p;
    }
}