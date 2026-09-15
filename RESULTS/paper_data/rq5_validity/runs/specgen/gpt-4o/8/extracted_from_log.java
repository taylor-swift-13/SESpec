public class Primes {

  //@ requires m >= 0;
  //@ ensures \result == n * m;
  static int mult(int n, int m) {
    if (m < 0) {
      return mult(n, -m);
    }
    if (m == 0) {
      return 0;
    }
    if (m == 1) {
      return n;
    }
    return n + mult(n, m - 1);
  }

  //@ requires m != 0;
  //@ ensures \result == 1 <==> (\exists int k; k >= 0; n == k * m);
  //@ ensures \result == 0 <==> (\forall int k; k >= 0; n != k * m);
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

  //@ requires n >= 0;
  //@ ensures \result == 1 <==> (\forall int k; 2 <= k && k < n; n % k != 0);
  //@ ensures \result == 0 <==> (\exists int k; 2 <= k && k < n; n % k == 0);
  static int is_prime(int n) {
    return is_prime_(n, n - 1);
  }

  //@ requires n >= 0 && m >= 0;
  //@ ensures \result == 1 <==> (\forall int k; 2 - 1 <= k && k <= m; n % k != 0);  
  //@ ensures \result == 0 <==> (\exists int k; 2 - 1 <= k && k < m; n % k == 0);  
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