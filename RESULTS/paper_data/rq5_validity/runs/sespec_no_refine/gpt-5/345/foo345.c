
/*@
  assigns \nothing;
  ensures \result == \sum(2, n, (integer k) evendiv(n, k));
*/
int foo345(int n) {

        int sum=0;
        
        /*@ 
          loop invariant 2 <= i <= n + 1;
          loop invariant n == n;
          loop invariant sum == \sum(2, i-1, (integer k) evendiv(n, k));
          loop assigns i, sum;
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
