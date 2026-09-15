
/*@
  logic integer count_divisors(int n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_divisors(n, lo, hi - 1) + (n % (hi - 1) == 0 ? 1 : 0);
*/

 /*@ requires n >= 0; @*/
const char * foo285(int n) {

    int count = 0;

    /*@ 
      loop invariant 1 <= i <= n + 1;
      loop invariant 0 <= count <= i - 1;
      loop invariant n == \at(n,Pre);
      loop invariant count == count_divisors(n, 1, i);
      loop invariant \forall integer k; 1 <= k < i ==> count_divisors(n,1,k+1) >= count_divisors(n,1,k);
      loop invariant (i == n + 1) ==> (count == count_divisors(n, 1, n + 1));
      loop assigns i, count;
    */
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    if (count % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
