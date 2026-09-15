int difference(int n);

/*@
    requires n >= 0;
    assigns \nothing;
    ensures \result == \sum integer i=1..n (i*i*i - i);
*/
int difference(int n) {

        int sum = 0;
        int sum1 = 0;
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant sum == \sum integer j=1..i-1 (j*j*j);
            loop assigns i, sum;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
        /*@
            loop invariant 1 <= i <= n+1;
            loop invariant sum1 == \sum integer j=1..i-1 j;
            loop assigns i, sum1;
            loop variant n - i + 1;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
        return sum - sum1;
}
