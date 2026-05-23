
/* Simple function: remove factors of two */

/* Note: no top-level ACSL predicate/logic is required for this example. */

int foo148(int n) {

    if(n <= 0) {
        return 0;
    }

    /*@
      loop invariant 1 <= n;
      loop invariant n % 2 == 0 || n % 2 == 1;
      loop invariant n == 1 || n/2 < n;
      loop invariant n % 2 == 0 ==> n >= 2;
      loop assigns n;
    */
    while (n % 2 == 0) {
        n /= 2;
    }

    return n == 1;
}
