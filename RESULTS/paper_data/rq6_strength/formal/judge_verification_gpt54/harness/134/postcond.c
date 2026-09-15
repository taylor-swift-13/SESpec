#include <limits.h>

/*@ assigns \nothing;
  ensures \result == x * y;
  ensures x == 0 || y == 0 ==> \result == 0;
  ensures (x >= 0 && y >= 0) ==> \result >= 0;
  ensures (x < 0 && y < 0) ==> \result >= 0;
  ensures ((x < 0) != (y < 0)) ==> \result <= 0;
  ensures (x >= 0 && y >= 0) ==> \result == x * y;
  ensures (x < 0 && y >= 0) ==> \result == x * y;
  ensures (x >= 0 && y < 0) ==> \result == x * y;
  ensures (x < 0 && y < 0) ==> \result == x * y; */
int stub_A(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int x, int y);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int x, int y) {
    return stub_A(x, y);
}

/*@ assigns \nothing;
  ensures \result == x * y;
  ensures x == 0 || y == 0 ==> \result == 0;
  ensures (x >= 0 && y >= 0) ==> \result >= 0;
  ensures (x < 0 && y < 0) ==> \result >= 0;
  ensures ((x < 0) != (y < 0)) ==> \result <= 0;
  ensures (x >= 0 && y >= 0) ==> \result == x * y;
  ensures (x < 0 && y >= 0) ==> \result == x * y;
  ensures (x >= 0 && y < 0) ==> \result == x * y;
  ensures (x < 0 && y < 0) ==> \result == x * y; */
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
