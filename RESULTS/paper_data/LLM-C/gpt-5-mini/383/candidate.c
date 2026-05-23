int divisor(int n);

 /*@
     requires n >= 1;
     assigns \nothing;
     ensures \result == \numof integer k; 1 <= k <= n && n % k == 0;
 */
int divisor(int n) {

        int count = 0;
        /*@ 
            loop invariant 1 <= i <= n+1;
            loop invariant 0 <= count <= n;
            loop invariant count == \numof integer k; 1 <= k < i && n % k == 0;
            loop assigns i, count;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
        return count;
}
