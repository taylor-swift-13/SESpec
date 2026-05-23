
/*@ logic integer divcount(integer n, integer i) =
      i <= 1 ? 0 : divcount(n, i - 1) + ((n % (i - 1)) == 0 ? 1 : 0);
*/

/*@ requires n >= 0; */
int foo383(int n) {

        int count = 0;
        
        /*@
          loop invariant 1 <= i <= n + 1;
          loop invariant 0 <= count <= i - 1;
          loop invariant count == divcount(n, i);
          loop invariant count == divcount(\at(n,Pre), i);
          loop invariant \forall integer k; 1 <= k < i ==> ((n % k) == 0 ==> divcount(n, k + 1) == divcount(n, k) + 1);
          loop invariant \forall integer k; 1 <= k < i && (n % k) == 0 ==> count >= 1;
          loop invariant (i <= \at(n,Pre)) ==> (count == divcount(n, i));
          loop invariant (i <= \at(n,Pre)) ==> (0 <= count <= i - 1);
          loop invariant n == \at(n,Pre);
          loop assigns i, count;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        return count;
}
