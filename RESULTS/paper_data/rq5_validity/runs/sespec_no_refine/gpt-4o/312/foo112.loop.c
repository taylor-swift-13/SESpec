
/*@
  predicate valid_v2(int v2, integer v2_pre) = 
    (v2_pre + 5 >= 0 && v2_pre <= 5) ==> 
    (v2 >= -5 && v2 <= 5);

  predicate valid_x1(int x1, integer x1_init, int v1, integer t) = 
    (x1 == x1_init + t * v1);

  predicate valid_x2(int x2, integer x2_init, integer t, integer v2_pre) = 
    (x2 == x2_init + t * v2_pre);

  predicate valid_x3(int x3, integer x3_init, int v3, integer t) = 
    (x3 == x3_init + t * v3);

  predicate valid_t(int t, integer t_init, integer t_current) = 
    (t == t_current);
*/

void foo112(int v1, int v2, int v3) {

    int x1;
    int x2;
    int x3;
    int t;

    x1 = 100;
    x2 = 75;
    x3 = -50;
    t = 0;

    /*@
      loop invariant valid_x1(x1, 100, v1, t);
      loop invariant valid_x3(x3, -50, v3, t);
      loop invariant valid_t(t, 0, t);
      loop invariant (!(\at(v2, Pre) + 5 >= 0 && \at(v2, Pre) <= 5)) ==> 
        ((t == 0) && (x3 == -50) && (x2 == 75) && (x1 == 100) && 
         (v3 == \at(v3, Pre)) && (v2 == \at(v2, Pre)) && (v1 == \at(v1, Pre)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop assigns x1, x3, x2, v2, t;
    */
    while (v2 + 5 >= 0 && v2 <= 5) {
        x1 = x1 + v1;
        x3 = x3 + v3;
        x2 = x2 + v2;
        if (x2 * 2 - x1 - x3 >= 0) {
            v2 = v2 - 1;
        } else if (x2 * 2 - x1 - x3 <= 0) {
            v2 = v2 + 1;
        }
        t = t + 1;
    }
}
