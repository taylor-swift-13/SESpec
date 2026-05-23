public class MulNested {
    //@ ensures \result == x * y;
    //@ assignable \nothing;
    public static int mulNested(int x, int y) {
        int res = 0, m = x, n = y, sign = 1;
        if(x < 0){
            m = -x;
            sign = -sign;
        }
        if(y < 0){
            n = -y;
            sign = -sign;
        }
        //@ maintaining 0 <= i && i <= m;
        //@ maintaining m >= 0 && n >= 0;
        //@ maintaining m == (x < 0 ? -x : x) && n == (y < 0 ? -y : y);
        //@ maintaining sign == (((x < 0) ^ (y < 0)) ? -1 : 1);
        //@ maintaining res == i * n;
        //@ decreases m - i;
        for(int i = 0; i < m; i++) {
            //@ maintaining 0 <= j && j <= n;
            //@ maintaining res == i * n + j;
            //@ decreases n - j;
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
        }
        return sign * res;
    }
}