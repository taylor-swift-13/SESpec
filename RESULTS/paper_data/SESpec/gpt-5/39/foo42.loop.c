
/* No additional predicates or logic functions are needed. */

void foo42(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      // Supplementary invariants: semantic progress, bounds, and exit implications
      loop invariant 0 <= t;                                   // iteration count is non-negative
      loop invariant x1 == 100 + t * v1;                       // functional progress: x1 accumulates v1 each step
      loop invariant x3 == -50 + t * v3;                       // functional progress: x3 accumulates v3 each step
      loop invariant x2 >= 75 - t * 5;                         // since v2 in loop is in [-5,5], x2 increases by v2 each step => lower bound
      loop invariant x2 <= 75 + t * 5;                         // corresponding upper bound
      loop invariant v3 == \at(v3,Pre);                        // v3 is never assigned; stable
      loop invariant v1 == \at(v1,Pre);                        // v1 is never assigned; stable
      loop invariant (v2 + 5 >= 0 && v2 <= 5) ==> (-5 <= v2 && v2 <= 5); // guard implies bound
      loop invariant (t == 0) ==> (x1 == 100 && x2 == 75 && x3 == -50);  // entry-state implication
      loop invariant (v2 + 5 < 0 || v2 > 5) ==> (t >= 0);      // exit implication: trivial but records t's relation at exit
      loop invariant (v2 + 5 >= 0 && v2 <= 5) ==> (t >= 0);    // during the loop, t is non-negative
      // Named-variable placeholders filled with specific bounds/equalities under the guard condition
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t >= 0);
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x1 == 100 + t * v1);
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x2 >= 75 - 5 * t && x2 <= 75 + 5 * t);
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x3 == -50 + t * v3);
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t == t);
      loop invariant (!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)));
      loop invariant v3 == \at(v3,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop assigns x1, x3, x2, v2, t;
    */
    while(v2 + 5 >= 0 && v2 <= 5){
       x1 = x1 + v1;
       x3 = x3 + v3;
       x2 = x2 + v2;
       if(x2 * 2 - x1 - x3 >= 0){
         v2 = v2 - 1;
       }
       else if(x2 * 2 - x1 - x3 <= 0){
         v2 = v2 + 1;
       }
       t = t + 1;
    }
}
