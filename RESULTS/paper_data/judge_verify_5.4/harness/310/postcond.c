#include <limits.h>

/*@ requires num < 0;
  assigns \nothing;
  ensures \result == -1 <==> num < 0;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= 0;
  ensures num >= 0 ==> \result * \result <= num;
  ensures num >= 0 ==> (\result + 1) * (\result + 1) > num; */
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

/*@ requires num < 0;
  assigns \nothing;
  ensures \result == -1 <==> num < 0;
  ensures num < 0 ==> \result == -1;
  ensures num >= 0 ==> \result >= 0;
  ensures num >= 0 ==> \result * \result <= num;
  ensures num >= 0 ==> (\result + 1) * (\result + 1) > num; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
