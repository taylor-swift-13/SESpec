
/*@
  assigns \nothing;
  ensures \result == n || (2 <= \result && n % \result == 0 && \result <= n / \result);
*/
int foo367(int n) {
    int i = 2;

    /*@
      loop invariant 2 <= i;
      loop invariant \forall integer j; 2 <= j < i ==> n % j != 0;
      loop assigns i;
    */
    while (i <= n / i) {
        if (n % i == 0) {
            return i;
        }
        i++;
    }

    return n;
}
