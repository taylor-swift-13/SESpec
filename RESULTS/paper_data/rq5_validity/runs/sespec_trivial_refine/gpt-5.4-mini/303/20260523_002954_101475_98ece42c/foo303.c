
/*@ logic integer foo303_rec(integer k) =
      k == 0 ? 2 :
      k == 1 ? 1 :
      foo303_rec(k - 1) + 2 * foo303_rec(k - 2); */
/*@ requires n >= 1;
    assigns \result \from n;
    ensures \result == foo303_rec(n);
    ensures \result >= 1;
    ensures n == 1 ==> \result == 1;
    ensures n > 1 ==> \result == foo303_rec(n - 1) + 2 * foo303_rec(n - 2);
*/
int foo303(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 5;
    }
    return foo303(n - 1) + 2 * foo303(n - 2);
}
