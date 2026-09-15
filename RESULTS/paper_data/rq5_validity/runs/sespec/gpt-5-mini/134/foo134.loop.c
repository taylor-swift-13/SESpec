
/*@
predicate non_negative(int z) = z >= 0;
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
          loop invariant non_negative(n);
          loop invariant res == i * n;
          loop invariant \forall integer k; 0 <= k < i ==> res >= k * n;
          loop invariant (i == m) ==> (res == m * n);
          loop invariant m == (\at(x,Pre) < 0 ? -\at(x,Pre) : \at(x,Pre));
          loop invariant n == (\at(y,Pre) < 0 ? -\at(y,Pre) : \at(y,Pre));
          loop assigns i, j, res;
        */
        for(int i = 0; i < m; i++) {
            
            /*@
              loop invariant 0 <= j <= n;
              loop invariant 0 <= i <= m;
              loop invariant non_negative(n);
              loop invariant res == i * n + j;
              loop invariant (j < n) ==> res >= i * n;
              loop assigns j, res;
            */
            for(int j = 0; j < n; j++) {
                res = res + 1;
            }
            
        }
            
        return sign * res;
}
