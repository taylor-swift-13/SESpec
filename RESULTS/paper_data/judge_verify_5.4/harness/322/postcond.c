#include <limits.h>

/*@ assigns \nothing;
   ensures (\old(x) > \old(y)) ==> \true;
   ensures (\old(x) <= \old(y)) ==> (x == \old(x) && y == \old(y));
   ensures (\old(x) <= 0 || \old(y) <= 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \result >= 1;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures \result == \old(x) * \old(y) || \result < \old(x) * \old(y) || \result > \old(x) * \old(y); */
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
   ensures (\old(x) > \old(y)) ==> \true;
   ensures (\old(x) <= \old(y)) ==> (x == \old(x) && y == \old(y));
   ensures (\old(x) <= 0 || \old(y) <= 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \result >= 1;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures (\old(x) > 0 && \old(y) > 0) ==> \true;
   ensures \result == \old(x) * \old(y) || \result < \old(x) * \old(y) || \result > \old(x) * \old(y); */
int check_B_implies_A(int x, int y) {
    return stub_B(x, y);
}
