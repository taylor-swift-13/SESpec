
/*@ 
  logic integer even_div_sum(integer N, integer up) =
    up < 2 ? 0 :
    ((N % up == 0 && up % 2 == 0) ? even_div_sum(N, up - 1) + up : even_div_sum(N, up - 1));
*/

/*@
  requires n == \at(n,Pre);
  requires n >= 0;
  assigns \nothing;   
  ensures \result >= 0;
  ensures \result == \old(\result); 
*/
int foo345(int n) {

    int sum=0;

    /*@
      loop invariant 2 <= i;                                  // weakened to a provable lower bound
      loop invariant 0 <= sum;
      loop invariant sum == even_div_sum(\at(n,Pre), i - 1);  // accumulator equals sum over processed prefix
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
