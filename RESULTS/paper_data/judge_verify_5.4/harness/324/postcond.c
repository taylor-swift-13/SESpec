#include <limits.h>

/*@ logic integer fact(integer n) = n <= 1 ? 1 : n * fact(n - 1); */

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \result <= 9;
  
  ensures number <= 1 ==> \result >= 0; */
int stub_A(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int number);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int number) {
    return stub_A(number);
}

/*@ assigns \nothing;
  ensures \result >= 0;
  ensures \result <= 9;
  
  ensures number <= 1 ==> \result >= 0; */
int check_B_implies_A(int number) {
    return stub_B(number);
}
