/*@
    requires n >= 0;
    ensures \result >= 0;
    ensures \result == \sum(2, n, (n % \lambda == 0 && \lambda % 2 == 0 ? \lambda : 0));
*/
int sumoffactors(int n) {

        int sum=0;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant sum >= 0;
            loop invariant sum == \sum(2, i-1, (n % \lambda == 0 && \lambda % 2 == 0 ? \lambda : 0));
            loop assigns i, sum;
            loop variant n - i;
        */
        for(int i=2; i<=n; i++)
        {
            if(n % i == 0)
            {
                if(i % 2 == 0)
                    sum += i;
            }
        }
        return sum;
}
