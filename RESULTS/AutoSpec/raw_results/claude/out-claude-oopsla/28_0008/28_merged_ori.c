#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


/*
 * From CAV'12 by Sharma et al.
 */

void main() {
  int x = 0;
  int y = 0;
  int n = 0;
  /*@
  loop invariant y == x;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant 0 <= n;
  loop assigns y;
  loop assigns x;
  loop assigns n;
  */
  while(unknown()) {
      x++;
      y++;
  }
  /*@
  loop invariant y == x;
  loop invariant n <= y;
  loop invariant n <= x;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while(x!=n) {
      x--;
      y--;
  }
  // @ assert y==n;
}
