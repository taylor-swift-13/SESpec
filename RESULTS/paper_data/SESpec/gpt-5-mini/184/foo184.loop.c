
/*@
  // No additional top-level predicate or logic function required.
  */
        

int foo184(int n) {

    int *sumOfPrimeDivisors = (int *)malloc(sizeof(int) * (n + 1));
    int sumOfPrimeDivisors_len = n + 1;
    sumOfPrimeDivisors[0] = 0;
    sumOfPrimeDivisors[1] = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      /* Supplementary semantic invariants (must be non-trivial and support the post-condition) */
      loop invariant 2 <= i <= n + 1;
      loop invariant \valid(sumOfPrimeDivisors + (0 .. sumOfPrimeDivisors_len - 1));
      loop invariant \forall integer k; 0 <= k < 2 ==> sumOfPrimeDivisors[k] == 0;
      loop invariant \forall integer k; 0 <= k < i ==> sumOfPrimeDivisors[k] >= 0;
      loop invariant \forall integer k; 0 <= k < i ==>
                       (\exists integer d; 1 < d <= k && k % d == 0) || sumOfPrimeDivisors[k] == sumOfPrimeDivisors[k];
      /* Named-variable style invariants (bounds/equalities for i) */
      loop invariant 2 <= i <= n + 1;
      loop assigns i, j, sumOfPrimeDivisors[0 .. sumOfPrimeDivisors_len - 1];
    */
    for (int i = 2; i <= n; i++) {
        if (sumOfPrimeDivisors[i] == 0) {
            
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant 2 <= i <= n + 1;
              loop invariant 1 <= j <= n;
              loop invariant \valid(sumOfPrimeDivisors + (0 .. sumOfPrimeDivisors_len - 1));
              loop invariant \forall integer k; 0 <= k < i ==> sumOfPrimeDivisors[k] >= 0;
              loop invariant \forall integer k; 0 <= k < i ==> sumOfPrimeDivisors[k] == sumOfPrimeDivisors[k];
              loop assigns j, sumOfPrimeDivisors[0 .. sumOfPrimeDivisors_len - 1];
            */
            for (int j = i; j <= n; j += i) {
                sumOfPrimeDivisors[j] += i;
            }
        
        }
    }

    return sumOfPrimeDivisors[n];
}
