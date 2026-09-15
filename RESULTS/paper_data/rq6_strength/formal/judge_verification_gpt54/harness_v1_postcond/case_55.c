#include <limits.h>



/*@loop invariant 2 <= x;
      loop invariant (y < 2) || (x <= y);
      loop invariant x >= 2;
      loop invariant y == \at(y,Pre);
      loop invariant x == 2 || x > 2;
      loop invariant (x < y) ==> (x < y + 1);
      loop invariant (2 < \at(y,Pre)) ==> (x <= \at(y,Pre));
      loop invariant (2 < \at(y,Pre)) ==> (x <= y);
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)));
      loop invariant y == \at(y,Pre);
      loop assigns x;*/
void stub_A(unsigned int y);

/*@loop invariant x == 2 || x > 2;
    loop invariant x <= y || x >= y / x;
    loop invariant x <= y || x >= 2;
    loop invariant x <= y || x > y / x;
    loop invariant \true;
    loop invariant \forall integer k; 2 <= k < x ==> k <= y;
    loop invariant 2 <= x;
    loop invariant 0 < x;
    loop assigns x;*/
void stub_B(unsigned int y);

/*@loop invariant x == 2 || x > 2;
    loop invariant x <= y || x >= y / x;
    loop invariant x <= y || x >= 2;
    loop invariant x <= y || x > y / x;
    loop invariant \true;
    loop invariant \forall integer k; 2 <= k < x ==> k <= y;
    loop invariant 2 <= x;
    loop invariant 0 < x;
    loop assigns x;*/
void check_A_implies_B(unsigned int y) {
    stub_A(y);
}

/*@loop invariant 2 <= x;
      loop invariant (y < 2) || (x <= y);
      loop invariant x >= 2;
      loop invariant y == \at(y,Pre);
      loop invariant x == 2 || x > 2;
      loop invariant (x < y) ==> (x < y + 1);
      loop invariant (2 < \at(y,Pre)) ==> (x <= \at(y,Pre));
      loop invariant (2 < \at(y,Pre)) ==> (x <= y);
      loop invariant (2 < \at(y,Pre)) ==> (x >= 2);
      loop invariant (!(2 < \at(y,Pre))) ==> ((x == 2)&&(y == \at(y,Pre)));
      loop invariant y == \at(y,Pre);
      loop assigns x;*/
void check_B_implies_A(unsigned int y) {
    stub_B(y);
}
