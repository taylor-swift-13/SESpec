#include <limits.h>


/*@
  predicate undef_data_at(int *p) = \true;
*/

/*@loop invariant 0 <= x <= 100;
      loop assigns x;*/
void stub_A();

/*@loop invariant x <= 100;
    loop invariant x % 2 == 0 || x % 2 == 1;
    loop invariant x % 1 == 0;
    loop invariant 0 <= x;
    loop assigns x;*/
void stub_B();

/*@loop invariant x <= 100;
    loop invariant x % 2 == 0 || x % 2 == 1;
    loop invariant x % 1 == 0;
    loop invariant 0 <= x;
    loop assigns x;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant 0 <= x <= 100;
      loop assigns x;*/
void check_B_implies_A() {
    stub_B();
}
