/*@
    requires n >= 0;
    ensures \result >= 0;
    ensures \forall integer d; 2 <= d <= n && n % d == 0 && d % 2 == 0 ==> \result >= d;
    assigns \nothing;
*/
int sumoffactors(int n);

int sumoffactors(int n) {

        int sum=0;
        /*@
            loop invariant 2 <= i <= n + 1;
            loop invariant sum >= 0;
            loop invariant sum == \sum(integer d; 2 <= d < i && n % d == 0 && d % 2 == 0; d);
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
