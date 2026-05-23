#include <limits.h>

/*@ logic integer foo7_sum(int n, integer m) =
    m < 0 ? foo7_sum(n, -m) :
    m == 0 ? 0 :
    n + foo7_sum(n, m - 1); */

/*@ requires m >= 0;
  decreases m;
  assigns \nothing;
  ensures \result == foo7_sum(n, m);
  ensures m == 0 ==> \result == 0;
  ensures m > 0 ==> \result == n + foo7_sum(n, m - 1); */
int stub_A(int n, int m);

/*@ requires n >= INT_MIN / (m == 0 ? 1 : m);
requires n >= INT_MIN / (m == 0 ? 1 : m) && n <= INT_MAX / (m == 0 ? 1 : m);
requires n == 0 || m <= INT_MAX;
requires n <= INT_MAX / (m == 0 ? 1 : m);
requires n <= INT_MAX && n >= INT_MIN;
requires n + (m - 1) * n >= INT_MIN;
requires n + (m - 1) * n <= INT_MAX;
requires m >= 0;
requires m == 0 || (n >= INT_MIN / (m == 1 ? 1 : m));
requires m <= INT_MAX;
ensures m > 0 ==> \result == n * m;
ensures m == 0 ==> \result == 0;
ensures \result == n * m;
ensures \result == 0;
behavior zero:;
behavior positive:;
assumes m > 0;
assumes m == 0;
assigns \nothing; */
int stub_B(int n, int m);

/*@ requires n >= INT_MIN / (m == 0 ? 1 : m);
requires n >= INT_MIN / (m == 0 ? 1 : m) && n <= INT_MAX / (m == 0 ? 1 : m);
requires n == 0 || m <= INT_MAX;
requires n <= INT_MAX / (m == 0 ? 1 : m);
requires n <= INT_MAX && n >= INT_MIN;
requires n + (m - 1) * n >= INT_MIN;
requires n + (m - 1) * n <= INT_MAX;
requires m >= 0;
requires m == 0 || (n >= INT_MIN / (m == 1 ? 1 : m));
requires m <= INT_MAX;
ensures m > 0 ==> \result == n * m;
ensures m == 0 ==> \result == 0;
ensures \result == n * m;
ensures \result == 0;
behavior zero:;
behavior positive:;
assumes m > 0;
assumes m == 0;
assigns \nothing; */
int check_A_implies_B(int n, int m) {
    return stub_A(n, m);
}

/*@ requires m >= 0;
  decreases m;
  assigns \nothing;
  ensures \result == foo7_sum(n, m);
  ensures m == 0 ==> \result == 0;
  ensures m > 0 ==> \result == n + foo7_sum(n, m - 1); */
int check_B_implies_A(int n, int m) {
    return stub_B(n, m);
}
