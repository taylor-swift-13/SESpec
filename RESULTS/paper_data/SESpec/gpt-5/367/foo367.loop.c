
/* No additional predicates or logic functions are needed. */

int foo367(int n) {

        int i = 2;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 2 <= i;                            // lower bound on i
              loop invariant n == \at(n,Pre);                   // n is unchanged
              loop invariant i == 2 + (i - 2);                  // equality relating i to its start (trivial but tracks offset)
              loop invariant \forall integer k; 2 <= k < i ==> n % k != 0;  // no divisor found in processed prefix
              loop invariant \forall integer k; 2 <= k < i ==> (k == 0 || n / k < n); // arithmetic well-formedness side fact
              loop invariant i == 2 ==> \true;                  // base-case compatibility at loop entry
              loop invariant 2 <= \at(n,Pre) ==> i <= \at(n,Pre); // tighter bound while n >= 2
              loop invariant i <= \at(n,Pre) || i > \at(n,Pre); // totality (helps some provers split cases)
              loop invariant (i > \at(n,Pre) / i) ==> (\forall integer k; 2 <= k < i ==> n % k != 0); // exit-implication persists facts
              loop invariant (i > \at(n,Pre) / i) ==> (i * i > \at(n,Pre));  // negated condition gives strict square bound
              loop invariant (2 <= \at(n,Pre) / 2) ==> ((\forall integer k; 2 <= k <= \at(n,Pre) / k ==> n % k != 0) ==> \false || \true);
              loop invariant (2 <= \at(n,Pre) / 2) ==> (\forall integer k; 2 <= k < i ==> k <= \at(n,Pre) / k);
              loop invariant (i <= \at(n,Pre) / i) ==> (i <= \at(n,Pre));    // simple bound derived from the loop guard
              loop invariant (i >= 3) ==> (i - 1 >= 2);                      // progress: we have processed at least one candidate > 2
              loop invariant \exists integer t; t == i - 2 && t >= 0;        // existence of a non-negative iteration count
              loop invariant (i > \at(n,Pre) / i) ==> (n == \at(n,Pre));     // exit-implication keeps n unchanged

              loop invariant (2 <= \at(n,Pre) / 2) ==> ( (i >= 2) && (i <= \at(n,Pre)) );
              loop invariant (2 <= \at(n,Pre) / 2) ==> (i >= 2);
              loop invariant (!(2 <= \at(n,Pre) / 2)) ==> ((i == 2)&&(n == \at(n,Pre)));
              loop invariant n == \at(n,Pre);
              loop assigns i;
            */
            while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
            
        return n;
}
