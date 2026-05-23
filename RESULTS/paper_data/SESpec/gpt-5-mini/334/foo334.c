
/*@
  logic integer cube_sum(integer m) =
    m <= 0 ? 0 : cube_sum(m - 1) + m * m * m;
*/

/*@
  requires n >= 0;
  assigns \nothing;
  ensures n == \at(n,Pre);
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> \result == cube_sum(n) - (n * (n + 1)) / 2;
  ensures \result == cube_sum(n) - (n * (n + 1)) / 2;
*/
int foo334(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /*@
          loop invariant 1 <= i && i <= n + 1;
          loop invariant 0 <= sum;
          loop invariant sum == cube_sum(i - 1);
          loop invariant (\forall integer k; 1 <= k && k < i ==> k * k * k >= 0);
          loop invariant (i <= \at(n,Pre)) ==> (sum == cube_sum(i - 1));
          loop invariant (i <= \at(n,Pre)) ==> (sum >= 0);
          loop invariant sum1 == 0;
          loop invariant n == \at(n,Pre);
          loop assigns i, sum;
        */
        for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        
            
        /*@
          loop invariant 1 <= i && i <= n + 1;
          loop invariant 0 <= sum1;
          loop invariant sum1 == (i > 1 ? ((i - 1) * i) / 2 : 0);
          loop invariant (\forall integer k; 1 <= k && k < i ==> ((k * (k + 1)) / 2) <= sum1);
          loop invariant (i <= n) ==> (sum1 == (i > 1 ? ((i - 1) * i) / 2 : 0));
          loop invariant !(i <= n) ==> (sum1 == (n * (n + 1)) / 2);
          loop assigns i, sum1;
        */
        for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
