#include <limits.h>

/*@ assigns \nothing;
  
  ensures \result >= 0;
  ensures count < 1 ==> \result == 0; */
int stub_A(int count);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int count);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int count) {
    return stub_A(count);
}

/*@ assigns \nothing;
  
  ensures \result >= 0;
  ensures count < 1 ==> \result == 0; */
int check_B_implies_A(int count) {
    return stub_B(count);
}
