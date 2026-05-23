
/*@
  logic integer sum_to(integer n) = n <= 1 ? 0 : n + sum_to(n - 1);
*/

int foo196(int n) {

        int sum=0;
        
            
        /*@
          loop invariant n == \at(n,Pre);
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
