
/*@
  requires \true;
*/

int foo391(int n) {

        int i = 1;
        int square = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i;                                   // bound for i
          loop invariant 1 <= square;                              // bound for square
          loop invariant n == \at(n,Pre);                          // n unchanged (already present, restated for clarity)
          loop invariant i >= 1 ==> square >= 1;                   // derived non-negativity consistency
          loop invariant i >= 1 ==> (i - 1) <= square;             // coarse lower relation tying i and square
          loop invariant i >= 1 ==> (i - 1) * (i - 1) <= square;   // monotone consistency (implied equality but kept as order fact)
          loop invariant i >= 2 ==> (i - 2) * (i - 2) < square;    // strict growth across iterations
          loop invariant \forall integer k; 1 <= k < i ==> (k * k) <= square;  // processed prefix: square upper-bounds all prior k^2
          loop invariant \exists integer k; 1 <= k < i ==> square == k * k;    // membership: square equals some prior k^2 (namely i-1)
          loop invariant (square <= n) ==> (i - 1) * (i - 1) <= n;             // while-condition implication
          loop invariant (i >= 2) ==> ((i - 2) * (i - 2) <= n ==> (i - 1) * (i - 1) <= n || square > n); // stepwise threshold relation
          loop invariant (i >= 2) ==> ((i - 2) * (i - 2) <= n);    // from initialization and monotonicity until crossing n
          loop invariant (square >= (i - 1)) ;                     // trivial numeric bound assisting solvers
          loop invariant (1 <= \at(n,Pre)) ==> (i >= 1) ;
          loop invariant (1 <= \at(n,Pre)) ==> (((square == 1)&&(i == 1)&&(n == \at(n,Pre))) || (square == (i - 1) * (i - 1)));
          loop invariant (!(1 <= \at(n,Pre))) ==> ((square == 1)&&(i == 1)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns square, i;
            */
            while (square <= n) {
            square = i*i;
            i++;
        }
            
        return square;
}
