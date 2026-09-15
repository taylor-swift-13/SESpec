int mult(int n, int m);
int multiple_of(int n, int m);
int is_prime(int n);
int is_prime_(int n, int m);

/*@
requires n >= 0;
requires n >= 0 || m == 0;
requires n >= 0 && m >= 0;
requires n <= INT_MAX - m;
requires m >= 0;
requires \true;
ensures n == 2 ==> \result == 1;
ensures n == 0 ==> \result == 1;
ensures n <= 1 ==> \result == 0;
ensures m > 1 ==> \result == n + mult(n, m - 1);
ensures m > 1 ==> \result == n * m;
ensures m == 1 ==> \result == n;
ensures m == 1 ==> \result == 1;
ensures m == 0 ==> \result == 0;
ensures m < 0 ==> \result == mult(n, -m);
ensures m < 0 ==> \result == \result; /* unreachable by requires */;
ensures m < 0 ==> \result == \result;
ensures \result == n * m;
ensures \result == 1 <==> n > 1 &&;
ensures \result == 1 <==> n == 0;
ensures \result == 0 ==> m == 0 || n == 0;
ensures \result == 0 <==> n <= 1 || (\exists integer m; 1 < m < n && n % m == 0);
ensures \result == 0 <==> n <= 1 || (\exists integer d; 1 < d < n && n % d == 0);
ensures \result == 0 <==> n != 0 && m == 0;
ensures \result != 0 ==> m == 1 || n != 0;
assigns \nothing;
\forall integer d; 2 <= d <= m ==> n % d != 0;
\forall integer d; 2 <= d < n ==> n % d != 0;
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
requires n >= 0;
requires n > 1;
requires n > 1 ==> \result == 0 || \result == 1;
requires n <= INT_MAX - m;
requires m >= 1;
requires m >= 0;
requires m > 0;
requires \valid_read(&n) && \valid_read(&m);
requires \true;
ensures n >= 0 ==> (\result == 0 || \result == 1);
ensures n > 1 ==> (\result == 0 <==> (\exists integer d; 1 < d < n && n % d == 0));
ensures n > 0 && m > 0 ==> \result == multiple_of(n, m);
ensures n > 0 && m > 0 ==> \result == multiple_of(n - m, m);
ensures n == 2 ==> \result == 1;
ensures n == 0 ==> \result == 1;
ensures n <= 1 ==> \result == 0;
ensures n < 0 ==> \result == multiple_of(-n, m);
ensures m > 1 ==> \result == n + mult(n, m - 1);
ensures m > 1 ==> \result == n * m;
ensures m == 1 ==> \result == n;
ensures m == 1 ==> \result == 1;
ensures m == 0 ==> \result == 0;
ensures m < 0 ==> \result == multiple_of(n, -m);
ensures \result == n * m;
ensures \result == 1 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> n == 0 || m == 1 || (n >= m && multiple_of(n - m, m) == 1);
ensures \result == 1 <==> (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> (\exists integer d; 2 <= d <= n && n % d == 0);
ensures \result == 1 <==> (\exists integer d; 1 < d < n && n % d == 0);
ensures \result == 0 <==> n <= 1 || (\exists integer d; 2 <= d < n && n % d == 0);
ensures \result == 0 <==> n <= 1 || (\exists integer d; 1 < d < n && n % d == 0);
ensures \result == 0 <==> m != 0 && n % m == 0;
ensures \result == 0 <==> (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 0 <==> (\forall integer d; 1 < d < n ==> n % d != 0);
ensures \result == 0 <==> (\exists integer d; 1 < d <= n && n % d == 0);
ensures \result == 0 <==> (\exists integer d; 1 < d < n && n % d == 0);
ensures \result != 0 ==> (\forall integer d; 1 < d <= n ==> n % d != 0);
ensures \result != 0 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result != 0 <==> m != 0 && n % m != 0;
assigns \nothing;
/*@;
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
requires n >= 0;
requires n > 1;
requires n > 1 ==> \result == 0 || \result == 1;
requires n <= INT_MAX - m;
requires m >= 1;
requires m >= 0;
requires m > 0;
requires \valid_read(&n) && \valid_read(&m);
requires \true;
ensures n >= 0 ==> (\result == 0 || \result == 1);
ensures n > 1 ==> (\result == is_prime_(n, n - 1));
ensures n > 1 ==> (\result == 1 <==> (\forall integer d; 2 <= d < n ==> n % d != 0));
ensures n > 1 ==> (\result == 0 <==> (\exists integer d; 2 <= d < n && n % d == 0));
ensures n > 1 ==> (\result == 0 <==> (\exists integer d; 1 < d < n && n % d == 0));
ensures n > 1 && m > 1 && multiple_of(n, m) == 0 ==> \result == 0;
ensures n > 1 && m > 1 && multiple_of(n, m) != 0 ==> \result == is_prime_(n, m - 1);
ensures n > 1 && m <= 1 ==> \result == 1;
ensures n > 0 && m > 0 ==> \result == multiple_of(n, m);
ensures n > 0 && m > 0 ==> \result == multiple_of(n - m, m);
ensures n == 2 ==> \result == 1;
ensures n == 0 ==> \result == 1;
ensures n <= 1 ==> \result == 0;
ensures n < 0 ==> \result == multiple_of(-n, m);
ensures m > 1 ==> \result == n + mult(n, m - 1);
ensures m > 1 ==> \result == n * m;
ensures m == 1 ==> \result == n;
ensures m == 1 ==> \result == 1;
ensures m == 0 ==> \result == 0;
ensures m < 0 ==> \result == multiple_of(n, -m);
ensures \result == n * m;
ensures \result == 1 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> n == 0 || m == 1 || (n >= m && multiple_of(n - m, m) == 1);
ensures \result == 1 <==> (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> (\exists integer d; 2 <= d <= n && n % d == 0);
ensures \result == 1 <==> (\exists integer d; 1 < d < n && n % d == 0);
ensures \result == 0 <==> n <= 1 || (\exists integer d; 2 <= d < n && n % d == 0);
ensures \result == 0 <==> n <= 1 || (\exists integer d; 1 < d < n && n % d == 0);
ensures \result == 0 <==> m != 0 && n % m == 0;
ensures \result == 0 <==> (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 0 <==> (\forall integer d; 1 < d < n ==> n % d != 0);
ensures \result == 0 <==> (\exists integer d; 1 < d <= n && n % d == 0);
ensures \result == 0 <==> (\exists integer d; 1 < d < n && n % d == 0);
ensures \result != 0 ==> (\forall integer d; 1 < d <= n ==> n % d != 0);
ensures \result != 0 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result != 0 <==> m != 0 && n % m != 0;
assigns \nothing;
/*@;
*/
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
