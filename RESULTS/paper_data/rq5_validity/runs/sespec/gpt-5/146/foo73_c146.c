
/*@ logic integer pow4(integer k) = (k <= 0 ? 1 : 4 * pow4(k - 1)); */
/*@
  assigns \nothing;
*/
int foo73_c146(int n) {

    if(n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;
      loop assigns n;
    */
    while (n % 4 == 0) {
        n /= 4;
    }

    return n == 1;
}
