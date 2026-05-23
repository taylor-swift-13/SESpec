
/*@
  logic integer compute_xa(integer xa, integer ya, integer x, integer y) =
    x - y * 2;

  logic integer compute_ya(integer xa, integer ya, integer x, integer y) =
    x * 2 + y;
*/

void foo124() {

    int x;
    int y;
    int xa;
    int ya;

    xa = 0;
    ya = 0;

    /*@
      loop invariant ((ya == 0) && (xa == 0)) || (xa == compute_xa(xa, ya, xa + ya * 2 + 1, (unknown() ? (ya - xa * 2 + (xa + ya * 2 + 1)) : (ya - xa * 2 - (xa + ya * 2 + 1)))));
      loop invariant ((ya == 0) && (xa == 0)) || (ya == compute_ya(xa, ya, xa + ya * 2 + 1, (unknown() ? (ya - xa * 2 + (xa + ya * 2 + 1)) : (ya - xa * 2 - (xa + ya * 2 + 1)))));
      loop assigns x, y, xa, ya;
    */
    while (unknown()) {
        x = xa + ya * 2 + 1;
        if (unknown()) {
            y = ya - xa * 2 + x;
        } else {
            y = ya - xa * 2 - x;
        }
        xa = x - y * 2;
        ya = x * 2 + y;
    }
}
