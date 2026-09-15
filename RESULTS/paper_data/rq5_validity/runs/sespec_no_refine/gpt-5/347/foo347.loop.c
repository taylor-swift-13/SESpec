
/*@
*/

int foo347(int x, int y) {

    if (y < 0) {
        y = -y;
    }
    int count = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant 1 <= i <= y + 1;
      loop invariant 0 <= count;
      loop invariant y >= 0;
      loop invariant y == \at(y,Pre) || y == -\at(y,Pre);
      loop invariant x == \at(x,Pre);
      loop assigns i, count;
    */
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }

    return count;
}
