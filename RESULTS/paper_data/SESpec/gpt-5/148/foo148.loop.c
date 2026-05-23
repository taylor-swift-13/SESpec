
/* No additional predicates or logic functions are required. */

int foo148(int n) {

    if(n <= 0) {
        return 0;
    }

    /*@
      loop invariant n > 0;                          // n stays positive
      loop invariant (n % 2 == 0) ==> n >= 2;        // even positive n is at least 2
      loop invariant (n % 2 == 0) ==> (n / 2) >= 1;  // one-step progress well-defined

      // Supplementary semantic invariants:
      loop invariant (n % 2 == 0) || (n % 2 == 1);   // parity is always defined; exit implies odd
      loop invariant n == 1 || n >= 1;               // lower bound preserved
      loop invariant (n % 2 == 0) ==> ((n/2) < n);   // strict decrease when taking a step
      loop invariant (n % 2 == 0) ==> ((n/2) % 1 == 0); // division by 2 keeps integer (trivial arithmetic)
      loop invariant (n % 2 == 1) ==> (n >= 1);      // at exit, odd n is at least 1
      loop invariant (n % 2 == 1) ==> (n == 1 || n >= 3); // odd positive integers are 1 or ≥3
      loop assigns n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
