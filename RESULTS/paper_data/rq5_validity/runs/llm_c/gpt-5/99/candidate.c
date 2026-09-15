int computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

/*@ logic integer INT_MAX_ = 2147483647; */
/*@ logic integer INT_MIN_ = -2147483647 - 1; */
/*@ logic integer imin(integer a, integer b) = a <= b ? a : b; */
/*@ logic integer imax(integer a, integer b) = a >= b ? a : b; */

/*@
  requires ax1 <= ax2;
  requires ay1 <= ay2;
  requires bx1 <= bx2;
  requires by1 <= by2;

  requires \let dx = imin(ax2,bx2) - imax(ax1,bx1);
           \let dy = imin(ay2,by2) - imax(ay1,by1);
           \let w = dx >= 0 ? dx : 0;
           \let h = dy >= 0 ? dy : 0;
           INT_MIN_ <= dx <= INT_MAX_ &&
           INT_MIN_ <= dy <= INT_MAX_ &&
           0 <= w && 0 <= h &&
           w * h <= INT_MAX_;

  assigns \nothing;

  ensures \result ==
           ((imin(ax2,bx2) - imax(ax1,bx1) > 0 ? (imin(ax2,bx2) - imax(ax1,bx1)) : 0)
            *
            (imin(ay2,by2) - imax(ay1,by1) > 0 ? (imin(ay2,by2) - imax(ay1,by1)) : 0));

  ensures 0 <= \result;
*/
int computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int minX2 = bx2;
        if(ax2 < bx2) {
            minX2 = ax2;
        }
        int maxX1 = bx1;
        if(ax1 > bx1) {
            maxX1 = ax1;
        }
        int minY2 = by2;
        if(ay2 < by2) {
            minY2 = ay2;
        }
        int maxY1 = by1;
        if(ay1 > by1) {
            maxY1 = ay1;
        }
        int overlapWidth = minX2 - maxX1;
        int overlapHeight = minY2 - maxY1;
        if(overlapWidth < 0) {
            overlapWidth = 0;
        }
        if(overlapHeight < 0) {
            overlapHeight = 0;
        }
        int overlapArea = overlapHeight * overlapWidth;
        return overlapArea;
}
