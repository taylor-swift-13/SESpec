int foo98(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);


/*@
  requires -20000 <= ax1 <= 20000;
  requires -20000 <= ay1 <= 20000;
  requires -20000 <= ax2 <= 20000;
  requires -20000 <= ay2 <= 20000;
  requires -20000 <= bx1 <= 20000;
  requires -20000 <= by1 <= 20000;
  requires -20000 <= bx2 <= 20000;
  requires -20000 <= by2 <= 20000;

  requires ax1 <= ax2;
  requires ay1 <= ay2;
  requires bx1 <= bx2;
  requires by1 <= by2;

  assigns \nothing;

  behavior empty:
    assumes ((ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1) <= 0) ||
            ((ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1) <= 0);
    ensures \result == 0;

  behavior nonempty:
    assumes ((ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1) > 0) &&
            ((ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1) > 0);
    ensures \result > 0;

  complete behaviors;
  disjoint behaviors;
*/
int foo98(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  int overlapWidth  = (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1);
  int overlapHeight = (ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1);
  int overlapArea = (overlapWidth > 0 ? overlapWidth : 0) *
                    (overlapHeight > 0 ? overlapHeight : 0);
  return overlapArea;
}