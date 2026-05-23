
/*@
  predicate divides(integer a, integer b) = a != 0 ==> (b % a) == 0;
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
