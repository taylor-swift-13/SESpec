
/*@
  requires \true;
  assigns \nothing;
  ensures \result == x * y;
  ensures x >= 0 && y >= 0 ==> \result >= 0;
  ensures x < 0 && y < 0 ==> \result >= 0;
  ensures (x < 0 && y >= 0) || (x >= 0 && y < 0) ==> \result <= 0;
*/
int foo134(int x, int y) {

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
      loop invariant sign == -1 || sign == 1;
      loop invariant n == (y < 0 ? -y : y);
      loop invariant m == (x < 0 ? -x : x);
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
