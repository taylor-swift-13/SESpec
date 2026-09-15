
/*@
  // No additional predicate or logic function is required for this program.
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
      loop invariant sign == -1;
      loop invariant n == -\at(y,Pre);
      loop invariant m == (x < 0 ? -\at(x,Pre) : \at(x,Pre));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns i, res;
    */
    for(int i = 0; i < m; i++) {
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop assigns j, res;
        */
        for(int j = 0; j < n; j++) {
            res = res + 1;
        }
    }
    
    return sign * res;
}
