int mult(int n, int m);
int multiple_of(int n, int m);
int is_prime(int n);
int is_prime_(int n, int m);

/*@
requires n >= 0;
requires n >= 0 || m == 0;
requires n >= 0 && m >= 0;
requires n == 0 || \abs(n) <= INT_MAX / (m == 0 ? 1 : m);
requires m >= 0;
requires m == 0 || n <= INT_MAX - mult(n, m - 1);
ensures n > 2 ==> (\result == 0 || \result == 1);
ensures n > 2 && m > 1 && multiple_of(n, m) == 0 ==> \result == 0;
ensures n > 2 && m > 1 && multiple_of(n, m) != 0 ==> \result == is_prime_(n, m - 1);
ensures n > 2 && m <= 1 ==> \result == 1;
ensures n > 0 && m > 0 ==> \result == multiple_of(n - m, m);
ensures n > 0 && m > 0 ==> (\result == 0 || \result == 1);
ensures n == 2 ==> \result == 1;
ensures n == 0 ==> \result == 1;
ensures n == 0 && m > 0 ==> \result == 1;
ensures n <= 1 ==> \result == 0;
ensures n < 0 ==> \result == multiple_of(-n, m);
ensures multiple_of(n, m) == 0 ==> \result == 0;
ensures m > 1 ==> \result == n + mult(n, m - 1);
ensures m > 1 ==> \result == n * m;
ensures m == 1 ==> \result == n;
ensures m == 1 ==> \result == 1;
ensures m == 0 ==> \result == 1;
ensures m == 0 ==> \result == 0;
ensures m <= 1 ==> \result == 1;
ensures m < 0 ==> \result == multiple_of(n, -m);
ensures \result == n * m;
ensures \result == is_prime_(n, n - 1);
ensures \result == 1 <==> n >= 2 &&;
ensures \result == 1 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> n > 1 && (\forall integer d; 1 < d < n ==> n % d != 0);
ensures \result == 1 <==> m != 0 && n % m == 0;
ensures \result == 1 <==> (n > 1 && (\forall integer d; m < d < n ==> n % d != 0));
ensures \result == 1 <==> (n > 1 && (\forall integer d; 1 < d <= m ==> n % d != 0));
ensures \result == 1 <==> (n == 0 || multiple_of(n, m) != 0);
ensures \result == 0 || \result == 1;
ensures \result == 0 <==> n <= 1 ||;
ensures \result == 0 <==> n != 0 && m != 0 && n % m == 0;
ensures \result == 0 <==> m == 0 || n % m != 0;
assigns \nothing;
\forall integer d; 2 <= d < n ==> n % d != 0;
(\exists integer d; 2 <= d < n && n % d == 0);
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
} else {;
} else if (n == 2) {;
return n + mult(n, m - 1);
return multiple_of(n, -m);
return multiple_of(n - m, m);
return multiple_of(-n, m); // 0;
return mult(n, -m);
return is_prime_(n, n - 1);
return is_prime_(n, m - 1);
return 1; // 1;
return 1;
return 0; // 0;
return 0;
requires n >= 0;
requires n >= 0 || m >= 0;
requires n >= 0 || m == 0;
requires n >= 0 && m >= 0;
requires n == 0 || m > 0;
requires n == 0 || m == 0 || n <= INT_MAX - n * (m - 1);
requires n == 0 || m == 0 || n <= INT_MAX - mult(n, m - 1);
requires n == 0 || m == 0 || n <= INT_MAX + m;
requires n == 0 || \abs(n) <= INT_MAX / (m == 0 ? 1 : m);
requires n <= INT_MAX;
requires m >= 0;
requires m >= 0 || n >= 0;
requires m == 0 || n <= INT_MAX - mult(n, m - 1);
requires m <= INT_MAX;
int multiple_of(int n, int m) {;
int mult(int n, int m);
int mult(int n, int m) {;
int is_prime_(int n, int m) {;
int is_prime(int n) {;
if (n == 0) {;
if (n <= 1) {;
if (n < 0) {;
if (multiple_of(n, m) == 0) {;
if (m == 1) {;
if (m == 0) {;
if (m <= 1) {;
if (m < 0) {;
ensures n >= 0 && m == 1 ==> \result == 1;
ensures n >= 0 && m == 0 ==> \result == 0;
ensures n >= 0 && m < 0 ==> \result == multiple_of(n, -m);
ensures n > 2 ==> \result == is_prime_(n, n - 1);
ensures n > 2 ==> (\result == 0 || \result == 1);
ensures n > 2 && m > 1 && multiple_of(n, m) == 0 ==> \result == 0;
ensures n > 2 && m > 1 && multiple_of(n, m) != 0 ==> \result == is_prime_(n, m - 1);
ensures n > 2 && m <= 1 ==> \result == 1;
ensures n > 2 && (\forall integer d; 2 <= d < n ==> n % d != 0) ==> \result == 1;
ensures n > 2 && (\exists integer d; 2 <= d < n && n % d == 0) ==> \result == 0;
ensures n > 1 ==> (\result == 1 <==> (\forall integer d; 2 <= d < n ==> n % d != 0));
ensures n > 0 && m > 0 ==> \result == multiple_of(n - m, m);
ensures n > 0 && m > 0 ==> (\result == 1 <==> n % m == 0);
ensures n > 0 && m > 0 ==> (\result == 0 || \result == 1);
ensures n == 2 ==> \result == 1;
ensures n == 0 ==> \result == 1;
ensures n == 0 ==> \result == 0;
ensures n == 0 && m > 0 ==> \result == 1;
ensures n <= 1 ==> \result == 0;
ensures n < 0 ==> \result == multiple_of(-n, m);
ensures multiple_of(n, m) == 0 ==> \result == 0;
ensures m > 1 ==> \result == n + mult(n, m - 1);
ensures m > 1 ==> \result == n * m;
ensures m == 1 ==> \result == n;
ensures m == 1 ==> \result == 1;
ensures m == 0 ==> \result == 1;
ensures m == 0 ==> \result == 0;
ensures m <= 1 ==> \result == 1;
ensures m < 0 ==> \result == multiple_of(n, -m);
ensures \result == n * m;
ensures \result == multiple_of(n, m);
ensures \result == is_prime_(n, n - 1);
ensures \result == 1 <==> n >= 2 &&;
ensures \result == 1 <==> n > 1 && (\forall integer d; 2 <= d < n ==> n % d != 0);
ensures \result == 1 <==> n > 1 && (\forall integer d; 1 < d < n ==> n % d != 0);
ensures \result == 1 <==> m == 0 || n % m != 0;
ensures \result == 1 <==> m != 0 && n % m == 0;
ensures \result == 1 <==> (n > 1 && (\forall integer d; m < d < n ==> n % d != 0));
ensures \result == 1 <==> (n > 1 && (\forall integer d; 1 < d <= m ==> n % d != 0));
ensures \result == 1 <==> (n > 1 && (\forall integer d; 1 < d < n ==> n % d != 0));
ensures \result == 1 <==> (n == 0 || multiple_of(n, m) != 0);
ensures \result == 0 || \result == 1;
ensures \result == 0 <==> n > 0 && m > 0 && n % m == 0;
ensures \result == 0 <==> n <= 1 ||;
ensures \result == 0 <==> n != 0 && m != 0 && n % m == 0;
ensures \result == 0 <==> m == 0 || n % m != 0;
ensures \result == 0 <==> (n <= 1 || (\exists integer d; 1 < d < n && n % d == 0));
assigns \nothing;
\forall integer d; 2 <= d < n ==> n % d != 0;
/*@;
(\exists integer d; 2 <= d < n && n % d == 0);
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
ensures \result == 0 || \result == 1;
ensures n <= 1 ==> \result == 0;
ensures n == 2 ==> \result == 1;
ensures n > 2 ==> \result == is_prime_(n, n - 1);
ensures n > 2 ==> (\result == 1 <==> (\forall integer d; 2 <= d < n ==> n % d != 0));
assigns \nothing;
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
