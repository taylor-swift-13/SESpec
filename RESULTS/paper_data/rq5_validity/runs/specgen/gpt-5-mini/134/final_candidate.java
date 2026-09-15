public class MulNested {
    /*@ 
      @ ensures \result == x * y;
      @*/
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
        /*@ 
          @ // m and n are the absolute values of x and y respectively
          @ maintaining 0 <= m && 0 <= n;
          @*/
        /*@ 
          @ // Outer loop: after k completed iterations (i), res == i * n
          @ maintaining 0 <= i && i <= m && res == i * n;
          @ decreases m - i;
          @*/
        for(int i = 0; i < m; i++) {
            /*@
              @ // Inner loop: after k completed iterations (j) of the inner loop, 
              @ // res == i * n + j
              @ maintaining 0 <= j && j <= n && res == i * n + j;
              @ decreases n - j;
              @*/
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
        }
        return sign * res;
    }
}