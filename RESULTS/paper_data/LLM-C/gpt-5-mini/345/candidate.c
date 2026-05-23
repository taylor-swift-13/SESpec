int sumoffactors(int n);

/*@
    requires n >= 1;
    assigns \nothing;
    ensures \result == (\sum integer i; 2 <= i <= n && n % i == 0 && i % 2 == 0; i);
*/
int sumoffactors(int n) {

        int sum=0;
        /*@
            loop invariant 2 <= i <= n+1;
            loop invariant sum >= 0;
            loop invariant sum == (\sum integer j; 2 <= j < i && n % j == 0 && j % 2 == 0; j);
            loop assigns i, sum;
            loop variant n - i + 1;
        */
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                if(i%2==0)
                    sum+=i;
            }
        }
        return sum;
}
