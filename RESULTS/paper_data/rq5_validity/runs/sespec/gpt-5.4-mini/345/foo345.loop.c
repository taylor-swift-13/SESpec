
/*@
  logic integer evendiv_sum(integer n, integer i) =
    i < 2 ? 0 :
    evendiv_sum(n, i - 1) + ((n % i == 0 && i % 2 == 0) ? i : 0);
*/

int foo345(int n) {

        int sum=0;
        
            
        /*@
          loop invariant 2 <= i;
          loop invariant 0 <= sum;
          loop invariant (i<=\at(n,Pre)) ==> (sum == evendiv_sum(n, i - 1));
          loop invariant (i<=\at(n,Pre)) ==> (0 <= sum);
          loop invariant (!(i<=\at(n,Pre))) ==> (sum == evendiv_sum(n, \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 && k % 2 == 0) ==> sum >= k;
          loop invariant sum > 0 ==> \exists integer k; 2 <= k < i && n % k == 0 && k % 2 == 0;
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
