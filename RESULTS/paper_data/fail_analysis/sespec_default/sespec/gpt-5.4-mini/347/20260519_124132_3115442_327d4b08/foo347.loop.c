
/*@
  logic integer abs_pre_y(integer pre_y) = pre_y < 0 ? -pre_y : pre_y;
*/

int foo347(int x, int y) {

    if (y < 0) {
        y = -y;
    }
    int count = 0;
    
    /*@
      loop invariant 1 <= i <= y + 1;
      loop invariant y == abs_pre_y(\at(y,Pre));
      loop invariant x == \at(x,Pre);
      loop invariant 0 <= count <= i - 1;
      loop assigns i, count;
    */
    for (int i = 1; i <= y; i++) {
        if (x % i == 0) {
            count = count + 1;
        }
    }
    
    return count;
}
