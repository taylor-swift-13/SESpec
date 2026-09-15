#include <limits.h>
#include <stddef.h>


/*@ 
  predicate undef_data_at;(int *p) = \true;
*/

/*@loop invariant x % 5 == 0;
      loop invariant x <= 105;
      loop assigns x;*/
void stub_A();

/*@loop invariant x % 5 == 0;
    loop assigns y;
    loop assigns x;*/
void stub_B();

/*@loop invariant x % 5 == 0;
    loop assigns y;
    loop assigns x;*/
void check_A_implies_B() {
    stub_A();
}

/*@loop invariant x % 5 == 0;
      loop invariant x <= 105;
      loop assigns x;*/
void check_B_implies_A() {
    stub_B();
}
