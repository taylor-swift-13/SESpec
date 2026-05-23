int mult(int n, int m);
int multiple_of(int n, int m);
int is_prime(int n);
int is_prime_(int n, int m);

/*@ 
  logic integer mult_model_nonneg(integer n, integer m)
    decreases m;
  = (m == 0 ? 0 : (m == 1 ? 1 : n + mult_model_nonneg(n, m - 1)));

  logic integer mult_model(integer n, integer m) =
    (m < 0 ? mult_model_nonneg(n, -m) : mult_model_nonneg(n, m));

  predicate is_multiple(integer n, integer m) =
    m != 0 && (\exists integer k; n == k * m);
*/

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == mult_model(n, m);
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
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;

  behavior zero_divisor:
    assumes m == 0;
    ensures \result == 0;

  behavior divisible:
    assumes m != 0 && is_multiple(n, m);
    ensures \result == 1;
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
  requires \true;
  assigns \nothing;
  ensures n <= 1 ==> \result == 0;
  ensures n == 2 ==> \result == 1;
  ensures \result == 0 || \result == 1;
*/
int is_prime(int n) {

    return is_prime_(n, n - 1);
}

/*@
  requires \true;
  assigns \nothing;
  ensures n <= 1 ==> \result == 0; // base case
  ensures n == 2 ==> \result == 1; // base case
  ensures n > 2 && m <= 1 ==> \result == 1; // reached end of search
  ensures \result == 0 || \result == 1;
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
