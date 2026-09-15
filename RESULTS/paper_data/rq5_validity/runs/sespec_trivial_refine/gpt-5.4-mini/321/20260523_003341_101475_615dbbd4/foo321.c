
/*@ logic integer igcd(integer a, integer b) =
      a < 0 ? igcd(-a, b) :
      b < 0 ? igcd(a, -b) :
      a == 0 ? b :
      igcd(b % a, a);
*/

/*@
  requires n >= 0;
  requires y >= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n * y;
*/
int foo321(int n, int y) {

    int ret = 1;
    int r = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= l;
      loop invariant n >= 0 ==> l <= n + 1;
      loop invariant 1 <= ret <= l;
      loop invariant (ret == 0 || n % ret == 0) && (ret == 0 || y % ret == 0);
      loop invariant \forall integer k; 1 <= k < l && n % k == 0 && y % k == 0 ==> k <= ret;
      loop assigns ret, l;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }

    r = (n * y) / ret;
    return r;
}
