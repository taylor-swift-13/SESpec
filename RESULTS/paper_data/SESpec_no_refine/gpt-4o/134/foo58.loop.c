
/*@
  // No additional predicates or logic functions are required for this program.
*/

int foo58(int x, int y) {

    int res = 0, m = x, n = y, sign = 1;
    if(x < 0){
        m = -x;
        sign = -sign;
    }
    if(y < 0){
        n = -y;
        sign = -sign;
    }

    /*@
      loop invariant 0 <= i <= m;
      loop invariant res == i * n;
      loop invariant m == \abs(x);
      loop invariant n == \abs(y);
      loop invariant sign == (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
      loop assigns i, res;
    */
    for(int i = 0; i < m; i++) {
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop invariant m == \abs(x);
          loop invariant n == \abs(y);
          loop assigns j, res;
        */
        for(int j = 0; j < n; j++) {
            res = res + 1;
        }
    }
    return sign * res;
}
