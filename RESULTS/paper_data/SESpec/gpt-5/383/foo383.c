
/*@
  assigns \nothing;
  ensures \result >= 0;
    ensures n >= 1 ==> \exists integer i; 1 <= i <= n && n % i == 1 ==> \result >= 1;
  ensures n >= 1 ==> \forall integer i; 1 <= i <= n && n % i == 0 ==> \result >= 1;
*/
int foo383(int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant 0 <= count <= i - 1;
          loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0) ==> 1 <= k && k <= \at(n,Pre);
          loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0) || (n % k == 0);
          loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0) ==> 1 <= k;
          loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0) ==> count == count;
          loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0) ==> count >= 1 || i == 1;
          loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0) ==> \exists integer t; 1 <= t < i && n % t == 0;
          loop invariant (i <= \at(n,Pre)) ==> (0 <= count && count <= i);
          loop invariant (i <= \at(n,Pre)) ==> (0 <= count && count <= \at(n,Pre));
          loop invariant \forall integer k; 1 <= k < i ==> (n % k == 0) ==> count >= 1 || i == 1;
          loop invariant \forall integer k; 1 <= k < i ==> (n % k != 0) ==> 0 <= count;
          loop assigns i, count;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        return count;
}
