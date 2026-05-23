#include <limits.h>


/*@
  logic integer undef_data_at(unsigned int *p) = 0;
*/
int unknown();

/*@loop invariant (y == 1) || (y == 0);
      loop invariant (y == 0) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
      loop invariant (y == 1) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
      loop assigns x, y;*/
void stub_A();

/*@loop invariant y == 1 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
    loop invariant y == 0 || y == 1;
    loop invariant y == 0 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
    loop invariant x % 3 == 0 || x % 3 == 1 || x % 3 == 2;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;*/
void stub_B();

/*@loop invariant y == 1 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
    loop invariant y == 0 || y == 1;
    loop invariant y == 0 ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
    loop invariant x % 3 == 0 || x % 3 == 1 || x % 3 == 2;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant (y == 1) || (y == 0);
      loop invariant (y == 0) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
      loop invariant (y == 1) ==> (x % 3 == 0 || x % 3 == 1 || x % 3 == 2);
      loop assigns x, y;*/
void check_B_implies_A() {
    stub_B();
}
