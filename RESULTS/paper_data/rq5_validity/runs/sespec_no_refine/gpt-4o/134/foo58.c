
/*@ logic integer abs_value(integer a) = a < 0 ? -a : a; */
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
      loop invariant m == abs_value(x);
      loop invariant n == abs_value(y);
      loop invariant sign == sign_value(x) * sign_value(y);
      loop assigns i, res;
    */
    for(int i = 0; i < m; i++) {
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant res == i * n + j;
          loop invariant m == abs_value(x);
          loop invariant n == abs_value(y);
          loop assigns j, res;
        */
        for(int j = 0; j < n; j++) {
            res = res + 1;
        }
    }
    /*@
      ensures \result == x * y;
    */
    return sign * res;
}
