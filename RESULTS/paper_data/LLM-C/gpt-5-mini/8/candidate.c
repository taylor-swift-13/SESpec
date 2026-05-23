int mult(int n, int m);
int multiple_of(int n, int m);
int is_prime(int n);
int is_prime_(int n, int m);

/*@
    ensures (m < 0) ==> \result == mult(n, -m);
    ensures m == 0 ==> \result == 0;
    ensures m == 1 ==> \result == 1;
    ensures m > 1 ==> \result == n + mult(n, m - 1);
    assigns \nothing;
*/
int mult(int n, int m) {

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
    ensures (m < 0) ==> \result == multiple_of(n, -m);
    ensures (n < 0) ==> \result == multiple_of(-n, m);
    ensures m == 0 ==> \result == 0;
    ensures n == 0 ==> \result == 1;
    ensures (m > 0 && n != 0 && !(n < 0) && !(m == 0) && !(n == 0)) ==> \result == multiple_of(n - m, m);
    assigns \nothing;
*/
int multiple_of(int n, int m) {

    if (m < 0) {
      return multiple_of(n, -m);
    }
    if (n < 0) {
      return multiple_of(-n, m); // 0
    }
    if (m == 0) {
      return 0; // 0
    }
    if (n == 0) {
      return 1; // 1
    }
    return multiple_of(n - m, m);
}

/*@
    ensures \result == is_prime_(n, n - 1);
    assigns \nothing;
*/
int is_prime(int n) {

    return is_prime_(n, n - 1);
}

/*@
    ensures n <= 1 ==> \result == 0;
    ensures n == 2 ==> \result == 1;
    ensures n > 2 && m <= 1 ==> \result == 1;
    ensures n > 2 && m > 1 && multiple_of(n, m) == 0 ==> \result == 0;
    ensures n > 2 && m > 1 && multiple_of(n, m) != 0 ==> \result == is_prime_(n, m - 1);
    assigns \nothing;
*/
int is_prime_(int n, int m) {

    if (n <= 1) {
      return 0; // 0
    } else if (n == 2) {
      return 1; // 1
    } else {
      if (m <= 1) {
        return 1; // 1
      } else {
        if (multiple_of(n, m) == 0) {
          return 0; // 0
        }
        return is_prime_(n, m - 1);
      }
    }
}
