
/*@ 
  logic integer abs_int(integer v) = v < 0 ? -v : v;
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
        for(int i = 0; i < m; i++) {
            /*@ 
                // >>> LOOP INVARIANT TO FILL <<<
                loop invariant 0 <= i <= m;
                loop invariant m == abs_int(x);
                loop invariant n == abs_int(y);
                loop invariant sign == (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
                loop invariant res == i * n;
                loop assigns i, res;
            */
            for(int j = 0; j < n; j++) {
                /*@ 
                    // >>> LOOP INVARIANT TO FILL <<<
                    loop invariant 0 <= j <= n;
                    loop invariant m == abs_int(x);
                    loop invariant n == abs_int(y);
                    loop invariant sign == (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
                    loop invariant res == i * n + j;
                    loop assigns j, res;
                */
                res = res + 1;
            }
        }
        return sign * res;
}
