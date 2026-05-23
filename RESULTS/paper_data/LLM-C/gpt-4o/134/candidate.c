/*@
    requires x >= INT_MIN && x <= INT_MAX;
    requires y >= INT_MIN && y <= INT_MAX;
    ensures \result == x * y;
    assigns \nothing;
*/
int mulNested(int x, int y);

int mulNested(int x, int y) {

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
        return sign * res;
}
