
/*@
  logic integer even_divisor_prefix_sum(integer n, integer i) =
    i <= 1 ? 0 :
    even_divisor_prefix_sum(n, i - 1) +
    ((i != 0 && n % i == 0 && i % 2 == 0) ? i : 0);
*/

/*@
   assigns \nothing;
*/
int foo345(int n) {

        int sum=0;
        
        /*@
          loop invariant 2 <= i;
          loop invariant n == \at(n,Pre);
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
