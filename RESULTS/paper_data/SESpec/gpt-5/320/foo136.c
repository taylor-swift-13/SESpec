
/*@ predicate divides(integer a, integer b) = \exists integer k; b == a * k; */

/*@ predicate gcd_of(integer a, integer b, integer d) =
      d >= 0 &&
      divides(d, a) && divides(d, b) &&
      (\forall integer e; e >= 0 && divides(e, a) && divides(e, b) ==> e <= d); */

/*@ predicate lcm_of(integer a, integer b, integer m) =
      m >= 0 &&
      divides(a, m) && divides(b, m) &&
      (\forall integer t; t >= 0 && divides(a, t) && divides(b, t) ==> m <= t); */

/*@
  requires n >= 0 && y >= 0;
  assigns \nothing;
*/
int foo136(int n, int y) {

    int ret = 1;
    int g = 1;
    if (n > y) {
        int r = n;
        n = y;
        y = r;
    }
        
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant l >= 2 ==> ret <= l - 1;
      loop assigns l, ret;
    */
    for (int l = 1; l <= n; l++) {
        if (n % l == 0 && y % l == 0) {
            ret = l;
        }
    }
        
    g = (n * y) / ret;
    return g;
}
