
/*@ 
  logic integer even_div_sum_upto(integer n, integer k) =
    k < 2 ? 0 :
    ((n % k == 0 && k % 2 == 0) ? k : 0) + even_div_sum_upto(n, k - 1);
*/

/*@
  assigns \nothing;
  ensures \result == even_div_sum_upto(n, n);
*/
int foo196_c345(int n) {

        int sum=0;
        
        /*@
          loop invariant i >= 2;
          loop invariant (i <= n) ==> (i >= 2 && i <= n);
          loop invariant sum == even_div_sum_upto(n, i-1);
          loop invariant (i > n) ==> (sum == even_div_sum_upto(n, n));
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
