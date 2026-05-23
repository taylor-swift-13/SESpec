
/*@ logic integer gcd_int(integer a, integer b) =
      a < 0 || b < 0 ? gcd_int(a < 0 ? -a : a, b < 0 ? -b : b)
                     : (a == 0 && b == 0 ? 0
                        : (a == 0 ? b
                           : (b == 0 ? a
                              : (\exists integer d; d > 0 &&
                                   (a % d) == 0 && (b % d) == 0 &&
                                   (\forall integer e; e > 0 && (a % e) == 0 && (b % e) == 0 ==> e <= d)) ))); */
/*@ logic integer lcm_int(integer a, integer b) =
      (gcd_int(a,b) == 0 ? 0 : (a / gcd_int(a,b)) * b); */
/*@
  assigns \nothing;
  ensures \result == lcm_int(\old(n), \old(y));
  ensures \result >= 0;
*/
int foo319(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }
        
    /*@
      loop invariant divides(ret, n);
      loop invariant divides(ret, y);
      loop invariant (j <= \at(y,Pre)) ==> (((l == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (divides(ret, n) && divides(ret, y)));
      loop invariant l == 1;
      loop assigns j, ret;
    */
    for (int j = 1; j <= n; j++) {
        if (n % j == 0 && y % j == 0) {
            ret = j;
        }
    }
            
    l = (n * y) / ret;
    return l;
}
