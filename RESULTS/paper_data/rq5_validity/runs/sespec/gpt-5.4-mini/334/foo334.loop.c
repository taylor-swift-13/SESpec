
/*@
  logic integer cubesum(integer k) =
    k <= 0 ? 0 : cubesum(k - 1) + k * k * k;
*/

/*@ 
  logic integer tri(integer k) =
    k <= 0 ? 0 : tri(k - 1) + k;
*/

/*@ 
  requires n >= 0;
*/
int foo334(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /*@
          loop invariant i >= 1;
          loop invariant sum == cubesum(i - 1);
          loop invariant 0 <= sum;
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop invariant (i <= \at(n,Pre)) ==> (sum >= sum1);
          loop invariant (i <= \at(n,Pre)) ==> (sum == cubesum(i - 1) && 0 <= sum);
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        
            
        /*@
          loop invariant i >= 1;
          loop invariant i <= n + 1;
          loop invariant sum >= 0;
          loop invariant sum1 == tri(i - 1);
          loop invariant 0 <= sum1;
          loop invariant n == \at(n,Pre);
          loop invariant (i <= n) ==> (sum1 == tri(i - 1) && 0 <= sum1);
          loop assigns i, sum1;
            */
            for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
