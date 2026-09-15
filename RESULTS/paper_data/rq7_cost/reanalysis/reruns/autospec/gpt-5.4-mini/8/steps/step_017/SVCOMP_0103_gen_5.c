int mult(int n, int m);
int multiple_of(int n, int m);
int is_prime(int n);
int is_prime_(int n, int m);

/*@
requires m >= 0;
requires n >= 0;
requires n <= INT_MAX - m;
ensures \result == n * m;
assigns \nothing;

requires m >= 0;
ensures \result == 1 <==> multiple_of(n, m) == 0;
assigns \nothing;

requires n >= 0;
ensures \result == 1 <==> n > 1 && (\forall integer d; 2 <= d < n ==> multiple_of(n, d) != 0);
assigns \nothing;

requires n >= 0;
requires m >= 0;
ensures \result == 1 <==> (\forall integer d; 2 <= d <= m ==> multiple_of(n, d) != 0);
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

int is_prime(int n) {

    return is_prime_(n, n - 1);
}

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
