
/*@
  requires \true;
*/


int foo334(int n) {

        int sum = 0;
        int sum1 = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant sum1 == 0;
          loop invariant sum >= 0;
          loop invariant i >= 1;
          loop invariant (i == 1) ==> (sum == 0);
          loop invariant \forall integer k; 1 <= k < i ==> (k*k*k >= 0);
          loop invariant (i <= n) ==> (sum + i*i*i >= sum);
          loop assigns i, sum;
            */
            for (int i = 1; i <= n; i++) {
            sum += i * i * i;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;
          loop invariant n == \at(n,Pre);
          loop invariant sum1 >= 0;
          loop invariant (i == 1) ==> (sum1 == 0);
          loop invariant \forall integer k; 1 <= k < i ==> (k >= 1);
          loop invariant (i <= n) ==> (sum1 + i >= sum1);
          loop assigns i, sum1;
            */
            for (int i = 1; i <= n; i++) {
            sum1 += i;
        }
            
        return sum - sum1;
}
