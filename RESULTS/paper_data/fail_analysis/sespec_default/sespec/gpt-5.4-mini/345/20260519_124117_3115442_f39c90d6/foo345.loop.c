
/*@
  logic integer even_divisor_prefix_sum(integer n, integer i) =
    (i <= 2) ? 0 :
    even_divisor_prefix_sum(n, i - 1) + ((n % (i - 1) == 0 && (i - 1) % 2 == 0) ? (i - 1) : 0);
*/

int foo345(int n) {

        int sum=0;
        
            
        /*@
          loop invariant 2 <= i;
          loop invariant n == \at(n,Pre);
          loop invariant sum == even_divisor_prefix_sum(\at(n,Pre), i);
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
