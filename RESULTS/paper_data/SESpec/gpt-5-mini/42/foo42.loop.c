

        
void foo42(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /*@
      // Supplementary invariants: describe how x1,x2,x3,t relate to initial values
      loop invariant 0 <= t;                                             // t is non-negative and counts iterations
      loop invariant x1 == 100 + t * \at(v1,Pre);                        // x1 accumulates v1 each iteration
      loop invariant x3 == -50 + t * \at(v3,Pre);                        // x3 accumulates v3 each iteration
      loop invariant (\exists integer d; d == \at(v2,Pre) - v2 && (d >= -t && d <= t)); // v2 changes by at most t in magnitude
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x1 == 100 + (t * \at(v1,Pre))); // restate for conditional branch
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (x3 == -50 + (t * \at(v3,Pre))); // x3 relation
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t >= 0); // t non-neg under guarded pre-range
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> ( (\at(v2,Pre) - t) <= v2 && v2 <= (\at(v2,Pre) + t) ); // v2 moves at most one per iter
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
