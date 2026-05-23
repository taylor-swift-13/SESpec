#include <limits.h>

/*@ requires x >= 0;
  requires y >= 0;
  requires x == 0 || y <= INT_MAX / x; */
void stub_A(int x,int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void stub_B(int x,int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
void check_A_implies_B(int x,int y) {
    stub_A(x, y);
}

/*@ requires x >= 0;
  requires y >= 0;
  requires x == 0 || y <= INT_MAX / x; */
void check_B_implies_A(int x,int y) {
    stub_B(x, y);
}
