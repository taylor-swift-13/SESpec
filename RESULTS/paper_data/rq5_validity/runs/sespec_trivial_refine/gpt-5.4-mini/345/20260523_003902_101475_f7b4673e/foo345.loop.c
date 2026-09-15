
/*@
logic integer even_div_sum(integer n, integer k) =
  (k < 2 ? 0 :
   even_div_sum(n, k - 1) + (((n % k) == 0 && (k % 2) == 0) ? k : 0));
*/

int foo345(int n) {

        int sum=0;
        
        /*@
          loop invariant 2 <= i <= n + 1;
          loop invariant sum == \sum integer j; 2 <= j < i && n % j == 0 && j % 2 == 0; j;
          loop invariant sum >= 0;
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
