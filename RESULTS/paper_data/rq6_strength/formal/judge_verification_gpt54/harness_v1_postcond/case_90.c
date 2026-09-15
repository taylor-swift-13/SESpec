#include <limits.h>



/*@requires x >= 0;*/
void stub_A(int x,int y);

/*@loop invariant x > y * q + r || x == y * q + r;
  loop invariant x > y * q + r || x <= y * q + r;
  loop invariant 0 <= x - (y * q + r);
  loop invariant 0 <= r;
  loop invariant 0 <= q;
  loop assigns r;
  loop assigns q;*/
void stub_B(int x,int y);

/*@loop invariant x > y * q + r || x == y * q + r;
  loop invariant x > y * q + r || x <= y * q + r;
  loop invariant 0 <= x - (y * q + r);
  loop invariant 0 <= r;
  loop invariant 0 <= q;
  loop assigns r;
  loop assigns q;*/
void check_A_implies_B(int x,int y) {
    stub_A(x, y);
}

/*@requires x >= 0;*/
void check_B_implies_A(int x,int y) {
    stub_B(x, y);
}
