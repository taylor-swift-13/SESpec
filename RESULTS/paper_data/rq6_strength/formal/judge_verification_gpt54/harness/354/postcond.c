#include <limits.h>

/*@ assigns \nothing; */
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

/*@ assigns \nothing; */
int check_B_implies_A(int num) {
    return stub_B(num);
}
