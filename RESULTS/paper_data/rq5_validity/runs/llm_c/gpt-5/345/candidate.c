int sumoffactors(int n);

/*@
  requires 0 <= n <= 92681;
  assigns \nothing;
  ensures \result == \sum(integer i; 2 <= i <= n; ((n % i) == 0 && (i % 2) == 0) ? i : 0);
  ensures 0 <= \result;
  ensures \result <= (n/2) * ((n/2) + 1);
*/
int sumoffactors(int n) {

        int sum=0;
        /*@
          loop invariant 2 <= i <= n+1;
          loop invariant 0 <= sum;
          loop invariant sum == \sum(integer k; 2 <= k < i; ((n % k) == 0 && (k % 2) == 0) ? k : 0);
          loop assigns sum, i;
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
