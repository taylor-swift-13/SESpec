
/*@
  assigns \nothing;
  ensures \result == x * y;
  ensures x == 0 ==> \result == 0;
  ensures y == 0 ==> \result == 0;
  ensures (x >= 0 && y >= 0) ==> \result >= 0;
  ensures (x <= 0 && y >= 0) ==> \result <= 0;
  ensures (x >= 0 && y <= 0) ==> \result <= 0;
  ensures (x <= 0 && y <= 0) ==> \result >= 0;
  ensures (\result >= 0 ? \result : -\result) == ((x >= 0 ? x : -x) * (y >= 0 ? y : -y));
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
          loop invariant 0 <= m;
          loop invariant 0 <= n;
          loop invariant res == i * n;
          loop invariant (i < m) ==> (res >= 0);
          loop invariant (i == m) ==> (res == m * n);
          loop invariant (n == 0) ==> (res == 0);
          loop invariant (m == 0) ==> (res == 0);
          loop invariant (i < -\at(x,Pre)) ==> (res == i * n);
          loop invariant y == \at(y,Pre);
          loop invariant x == \at(x,Pre);
          loop assigns i, res;
        */
        for(int i = 0; i < m; i++) {
            /*@
              loop invariant 0 <= j <= n;
              loop invariant res == i * n + j;
              loop assigns res, j;
            */
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
        }
            
        return sign * res;
}
