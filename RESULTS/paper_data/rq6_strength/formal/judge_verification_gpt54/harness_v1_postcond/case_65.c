#include <limits.h>


/*@
        predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION = \true;
        */

/*@loop invariant (0 < 2 * \at(k,Pre)) ==> (0 <= i && i <= 2 * k);
          loop invariant (!(0 < 2 * \at(k,Pre))) ==> ((i == 0)&&(n == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns n, i;*/
void stub_A(int k);

/*@loop invariant n == (i + 1) / 2;
    loop invariant n <= i;
    loop invariant n <= (i + 1) / 2;
    loop invariant i / 2 <= n;
    loop invariant i - 1 <= n * 2;
    loop invariant 0 <= n;
    loop invariant 0 <= i;
    loop assigns n;
    loop assigns i;*/
void stub_B(int k);

/*@loop invariant n == (i + 1) / 2;
    loop invariant n <= i;
    loop invariant n <= (i + 1) / 2;
    loop invariant i / 2 <= n;
    loop invariant i - 1 <= n * 2;
    loop invariant 0 <= n;
    loop invariant 0 <= i;
    loop assigns n;
    loop assigns i;*/
void check_A_implies_B(int k) {
    stub_A(k);
}

/*@loop invariant (0 < 2 * \at(k,Pre)) ==> (0 <= i && i <= 2 * k);
          loop invariant (!(0 < 2 * \at(k,Pre))) ==> ((i == 0)&&(n == 0)&&(k == \at(k,Pre)));
          loop invariant k == \at(k,Pre);
          loop assigns n, i;*/
void check_B_implies_A(int k) {
    stub_B(k);
}
