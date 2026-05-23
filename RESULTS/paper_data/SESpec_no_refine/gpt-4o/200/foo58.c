
/*@
  logic integer abs_value(integer x) = x < 0 ? -x : x;
*/
/*@
  requires \true;
  assigns \nothing;
  ensures \result == x * y;
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
      loop invariant sign == (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
      loop invariant n == abs_value(\at(y,Pre));
      loop invariant m == abs_value(\at(x,Pre));
      loop invariant y == \at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns i, res;
      loop variant m - i;
    */
    for(int i = 0; i < m; i++) {
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop assigns j, res;
          loop variant n - j;
        */
        for(int j = 0; j < n; j++) {
            res = res + 1;
        }
    }
    
    /*@
      ensures \result == sign * (abs_value(\at(x,Pre)) * abs_value(\at(y,Pre)));
    */
    return sign * res;
}
