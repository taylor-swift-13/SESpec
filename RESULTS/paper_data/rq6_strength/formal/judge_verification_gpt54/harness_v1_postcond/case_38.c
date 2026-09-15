#include <limits.h>


/*@ 
  logic integer abs_int(integer x) = x < 0 ? -x : x;
*/

/*@loop invariant t >= 0;
      loop invariant x1 == 100 + t * v1;
      loop invariant x3 == -50 + t * v3;
      loop invariant v1 == \at(v1,Pre);
      loop invariant v3 == \at(v3,Pre);
      loop invariant \true;
      loop invariant 75 - 5 * t <= x2 <= 75 + 5 * t;
      loop invariant x2 >= 75 - 5 * t;
      loop invariant x2 <= 75 + 5 * t;
      loop invariant t == 0 ==> x1 == 100 && x2 == 75 && x3 == -50;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t <= \at(v2,Pre) + 5 || t >= 0);
      loop invariant \true;
      loop invariant (!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)));
      loop invariant v3 == \at(v3,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop assigns x1, x3, x2, v2, t;*/
void stub_A(int v1, int v2, int v3);

/*@loop invariant x3 == -50 + t * v3;
    loop invariant x1 == 100 + t * v1;
    loop invariant 0 <= t;
    loop assigns x3;
    loop assigns x2;
    loop assigns x1;
    loop assigns v2;
    loop assigns t;*/
void stub_B(int v1, int v2, int v3);

/*@loop invariant x3 == -50 + t * v3;
    loop invariant x1 == 100 + t * v1;
    loop invariant 0 <= t;
    loop assigns x3;
    loop assigns x2;
    loop assigns x1;
    loop assigns v2;
    loop assigns t;*/
void check_A_implies_B(int v1, int v2, int v3) {
    stub_A(v1, v2, v3);
}

/*@loop invariant t >= 0;
      loop invariant x1 == 100 + t * v1;
      loop invariant x3 == -50 + t * v3;
      loop invariant v1 == \at(v1,Pre);
      loop invariant v3 == \at(v3,Pre);
      loop invariant \true;
      loop invariant 75 - 5 * t <= x2 <= 75 + 5 * t;
      loop invariant x2 >= 75 - 5 * t;
      loop invariant x2 <= 75 + 5 * t;
      loop invariant t == 0 ==> x1 == 100 && x2 == 75 && x3 == -50;
      loop invariant (\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5) ==> (t <= \at(v2,Pre) + 5 || t >= 0);
      loop invariant \true;
      loop invariant (!(\at(v2,Pre) + 5 >= 0 && \at(v2,Pre) <= 5)) ==> ((t == 0)&&(x3 == -50)&&(x2 == 75)&&(x1 == 100)&&(v3 == \at(v3,Pre))&&(v2 == \at(v2,Pre))&&(v1 == \at(v1,Pre)));
      loop invariant v3 == \at(v3,Pre);
      loop invariant v1 == \at(v1,Pre);
      loop assigns x1, x3, x2, v2, t;*/
void check_B_implies_A(int v1, int v2, int v3) {
    stub_B(v1, v2, v3);
}
