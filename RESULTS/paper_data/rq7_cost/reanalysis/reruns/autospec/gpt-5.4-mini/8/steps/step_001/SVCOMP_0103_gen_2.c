/*@ 
    requires m >= 0;
    ensures \result == n * m;
    assigns \nothing;
*/
int mult(int n, int m);

/*@ 
    requires m >= 0;
    ensures \result == 0 <==> \exists integer k; k >= 1 && n == k * m;
    assigns \nothing;
*/
int multiple_of(int n, int m);

/*@ 
    ensures \result == 1 <==> n >= 2 && (\forall integer d; 2 <= d < n ==> n % d != 0);
    assigns \nothing;
*/
int is_prime(int n);

/*@ 
    requires m >= 0;
    ensures \result == 1 <==> n >= 2 && (\forall integer d; m <= d < n ==> n % d != 0);
    assigns \nothing;
*/
int is_prime_(int n, int m);

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