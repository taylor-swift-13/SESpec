
/*@
  logic integer gcd(int a, int b) =
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  requires \at(n,Pre) > \at(y,Pre) && (l == 1) * (ret == 1) * (y == \at(n,Pre)) * (n == \at(y,Pre));
*/
int foo135(int n, int y) {

    int ret = 1;
    int l = 1;
    if (n > y) {
        int g = n;
        n = y;
        y = g;
    }

    /*@
      loop invariant 1 <= j <= \at(y,Pre);
      loop invariant (j <= \at(y,Pre)) ==> (((l == 1)&&(ret == 1)&&(y == \at(n,Pre))&&(n == \at(y,Pre))) || (ret == gcd(\at(n,Pre), \at(y,Pre))));
      loop invariant (!(j <= \at(y,Pre))) ==> ((l == 1)&&(ret == gcd(\at(n,Pre), \at(y,Pre)))&&(y == \at(n,Pre))&&(n == \at(y,Pre)));
      loop invariant l == 1;
      loop invariant y == \at(n,Pre);
      loop invariant n == \at(y,Pre);
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
