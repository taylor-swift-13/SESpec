
/*@
*/

/*@ logic boolean is_prime(integer p) =
      p >= 2 &&
      (\forall integer d; 2 <= d <= p - 1 ==> p % d != 0); */
/*@ logic integer spd_from(integer x, integer k) =
      k > x ? 0 :
      (is_prime(k) && x % k == 0 ? k : 0) + spd_from(x, k + 1); */
/*@ logic integer spd(integer x) = spd_from(x, 2); */
/*@
  requires n >= 1;
  assigns \nothing;
  ensures n == \old(n);
  ensures \result == spd(n);
  assigns \nothing;
*/
int foo39_c184(int n) {

        int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
        int sumOfPrimeDivisors_len = n + 1;
        sumOfPrimeDivisors[0] = 0;
        sumOfPrimeDivisors[1] = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= i <= n+1;
          loop invariant \forall integer k; 0 <= k < 2 ==> sumOfPrimeDivisors[k] == 0;
          loop invariant \forall integer k; 2 <= k < i ==> sumOfPrimeDivisors[k] >= 0;
          loop invariant \forall integer k; i <= k <= n ==> sumOfPrimeDivisors[k] >= 0;
          loop assigns i, sumOfPrimeDivisors[..];
            */
            for (int i = 2; i <= n; i++) {
            if (sumOfPrimeDivisors[i] == 0) {
                
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant i >= 2 && i <= n;
              loop invariant j >= i && j <= n + i;
              loop invariant ((j - i) % i) == 0;
              loop invariant \forall integer k; 0 <= k < j ==> 
                               ( (k % i) == 0 ==> sumOfPrimeDivisors[k] == \at(sumOfPrimeDivisors[k], Pre) + i ) &&
                               ( (k % i) != 0 ==> sumOfPrimeDivisors[k] == \at(sumOfPrimeDivisors[k], Pre) );
              loop assigns sumOfPrimeDivisors[..];
            */
            for (int j = i; j <= n; j += i) {
                    sumOfPrimeDivisors[j] += i;
                }
            
            }
        }
            

        return sumOfPrimeDivisors[n];
}
