#include <limits.h>

/*@ requires number >= 2;
  assigns \nothing;
  ensures number == 1 ==> \result == 1;
  ensures number != 1 ==> \result >= 0;
  ensures number != 1 && number < 2 ==> \result == 0 ;
  ensures number != 1 && \result == 0 ==> (\forall integer d; 2 <= d && d <= number / d ==> number % d != 0);
  ensures number != 1 && \result > 0 ==> \true; */
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

/*@ requires number >= 2;
  assigns \nothing;
  ensures number == 1 ==> \result == 1;
  ensures number != 1 ==> \result >= 0;
  ensures number != 1 && number < 2 ==> \result == 0 ;
  ensures number != 1 && \result == 0 ==> (\forall integer d; 2 <= d && d <= number / d ==> number % d != 0);
  ensures number != 1 && \result > 0 ==> \true; */
int check_B_implies_A(int number) {
    return stub_B(number);
}
