
/*@
  requires n > 0;
  ensures \result >= 0;
*/

int foo323(int n) {

    int count = 0;
    if (n == 1) return 1;

    /*@
      loop invariant count >= 0;
      loop invariant count <= i - 2; // count cannot exceed the number of iterations
      loop invariant \forall integer k; 2 <= k < i ==> (n % k != 0 || n / k != k); // Refined condition for preservation
      loop invariant \forall integer k; 2 <= k < i ==> (n % k == 0 ==> count >= 1); // Retained valid invariant
      loop assigns i, count;
    */
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            count++;
            if (n / i == i) {
                break;
            }
        }
    }

    return count;
}
