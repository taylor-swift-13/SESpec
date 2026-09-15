#include <limits.h>

/*@ logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1); */

/*@ requires num >= 0;
  requires num <= 12;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result <= 99;
  ensures num == 0 ==> \result == 1; */
int stub_A(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int num);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int num) {
    return stub_A(num);
}

/*@ requires num >= 0;
  requires num <= 12;
  assigns \nothing;
  ensures \result == fact(num) % 100;
  ensures 0 <= \result <= 99;
  ensures num == 0 ==> \result == 1; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
