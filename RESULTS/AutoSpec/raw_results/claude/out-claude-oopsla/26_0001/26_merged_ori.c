#include <assert.h>

int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {
  int w = 1, z = 0, x = 0, y = 0;
  while (unknown1()) {
    /*@
    loop invariant z == 2 * x;
    loop invariant x == y;
    loop invariant w == z + 1;
    loop invariant w % 2 == 1;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    ```c;
    ```;
    Looking at the nested loop structure and the assertion `x == y` that must hold at the end, I need to determine what invariants preserve this relationship.;
    Let me trace through the code:;
    For the assertion `x == y` to hold, the invariant must maintain `x == y` throughout.;
    Analyzing the logic:;
    - This preserves `x == y`;
    - Inner loop 2: sets `z = x + y` and `w = z + 1`;
    - Inner loop 1: increments `x` when `w % 2 == 1`, increments `y` when `z % 2 == 0`;
    - Initially: `w = 1, z = 0, x = 0, y = 0`;
    - In loop 1 with `w` odd and `z` even (since `z = 2x`): both `x++` and `y++` execute together;
    - If `x == y` initially, then in loop 2: `z = x + y = 2x`, so `w = 2x + 1` (always odd);
    */
    while (unknown2()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
    while (unknown4()) {
      z = x + y;
      w = z + 1;
    }
  }
  // @ assert x == y;
}