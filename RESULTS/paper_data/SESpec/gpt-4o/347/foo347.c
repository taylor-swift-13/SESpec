
/*@
  requires \true;
  assigns \nothing;
  ensures y < 0 ==> \result == -\old(y);
  ensures \result >= 0;
*/
int foo347(int x, int y) {

    if (y < 0) {
        y = -y;
    }
    int count = 0;

    /*@
      loop invariant 1 <= i && i <= y + 1;
      loop invariant y >= 0;
      loop invariant x == \at(x, Pre);
      loop invariant count >= 0;
      loop assigns count;
    */
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }

    return count;
}
