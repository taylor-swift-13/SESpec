public class Primes {

  /*@
    @ ensures ( (m < 0 ? -m : m) == 0 ) ==> \result == 0;
    @ ensures ( (m < 0 ? -m : m) != 0 ) ==> \result == (((m < 0 ? -m : m) - 1) * n + 1);
    @*/
  static int mult(int n, int m) {
    if (m < 0) {
      return mult(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    if (m == 1) {
      return 1;
    }
    return n + mult(n, m - 1);
  }

  /*@
    @ // multiple_of returns 1 exactly when the absolute value of n is a non-negative integer
    @ // multiple of the absolute value of m (and returns 0 otherwise). The postcondition
    @ // characterizes the relation when the function terminates.
    @ ensures \result == 1 <==> ( (m != 0) && (\exists int k; k >= 0 && ((n < 0 ? -n : n) == k * (m < 0 ? -m : m))) );
    @ ensures \result == 0 <==> !((m != 0) && (\exists int k; k >= 0 && ((n < 0 ? -n : n) == k * (m < 0 ? -m : m))) );
    @*/
  static int multiple_of(int n, int m) {
    if (m < 0) {
      return multiple_of(n, -m);
    }
    if (n < 0) {
      return multiple_of(-n, m); // false
    }
    if (m == 0) {
      return 0; // false
    }
    if (n == 0) {
      return 1; // true
    }
    return multiple_of(n - m, m);
  }

  /*@
    @ // is_prime returns 1 exactly when n is a prime number (standard definition):
    @ // n > 1 and there is no divisor d with 2 <= d <= n-1 that divides n.
    @ ensures \result == 1 <==> (n > 1 && (\forall int d; 2 < d && d < n-1; multiple_of(n, d) == 0));  
    @ ensures \result == 0 <==> !(n > 1 && (\forall int d; 2 <= d && d <= n-1; multiple_of(n, d) == 0));
    @*/
  static int is_prime(int n) {
    return is_prime_(n, n - 1);
  }

  /*@
    @ // is_prime_(n,m) returns 1 if, among divisors 2..m, none divide n (and n>1).
    @ // In particular, when m == n-1 this corresponds to primality of n.
    @ ensures \result == 1 <==> (n > 1 && (\forall int d; 2 < d && d <= m; multiple_of(n, d) == 0));  
    @ ensures \result == 0 <==> !(n > 1 && (\forall int d; 2 < d && d < m; multiple_of(n, d) == 0));  
    @*/
  static int is_prime_(int n, int m) {
    if (n <= 1) {
      return 0; // false
    } else if (n == 2) {
      return 1; // true
    } else {
      if (m <= 1) {
        return 1; // true
      } else {
        if (multiple_of(n, m) == 0) {
          return 0; // false
        }
        return is_prime_(n, m - 1);
      }
    }
  }

}