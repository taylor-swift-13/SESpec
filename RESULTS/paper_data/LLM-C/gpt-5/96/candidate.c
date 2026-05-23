int computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

/*@
  requires ax1 <= ax2;
  requires ay1 <= ay2;
  requires bx1 <= bx2;
  requires by1 <= by2;

  requires -1000000000 <= ax1 && ax1 <= 1000000000;
  requires -1000000000 <= ay1 && ay1 <= 1000000000;
  requires -1000000000 <= ax2 && ax2 <= 1000000000;
  requires -1000000000 <= ay2 && ay2 <= 1000000000;
  requires -1000000000 <= bx1 && bx1 <= 1000000000;
  requires -1000000000 <= by1 && by1 <= 1000000000;
  requires -1000000000 <= bx2 && bx2 <= 1000000000;
  requires -1000000000 <= by2 && by2 <= 1000000000;

  // Size bounds to prevent all intermediate overflows:
  // Each rectangle side length <= 32767 ensures each area <= 32767*32767,
  // and area1 + area2 stays within int range.
  requires 0 <= ax2 - ax1 && ax2 - ax1 <= 32767;
  requires 0 <= ay2 - ay1 && ay2 - ay1 <= 32767;
  requires 0 <= bx2 - bx1 && bx2 - bx1 <= 32767;
  requires 0 <= by2 - by1 && by2 - by1 <= 32767;

  assigns \nothing;

  // Exact result as computed by the implementation
  ensures \result ==
    ((ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1)
     - ((( (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1) ) > 0 ?
           ( (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1) ) : 0)
        *
        ( ((ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1) ) > 0 ?
          ( (ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1) ) : 0)));

  // Non-negativity under the above preconditions (no overflow)
  ensures \result >= 0;

  // If there is no horizontal or vertical overlap, result is the sum of areas
  ensures
    \let w = ((ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1));
    \let h = ((ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1));
    ((w <= 0) || (h <= 0)) ==>
      \result == (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);

  // Symmetric overlap computation form (redundant but documents intent)
  ensures \let ow = ((ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1));
          \let oh = ((ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1));
          \let pw = (ow > 0 ? ow : 0);
          \let ph = (oh > 0 ? oh : 0);
          \result == (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - pw*ph;
*/
int computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
        /*@ assert ax2 - ax1 >= 0 && ay2 - ay1 >= 0; */
        /*@ assert bx2 - bx1 >= 0 && by2 - by1 >= 0; */
        /*@ assert area1 >= 0 && area2 >= 0; */

        int overlapWidth = (ax2<bx2?ax2:bx2) - (ax1>bx1?ax1:bx1), overlapHeight = (ay2<by2?ay2:by2) - (ay1>by1?ay1:by1);
        /*@ assert overlapWidth == ((ax2<bx2?ax2:bx2) - (ax1>bx1?ax1:bx1)); */
        /*@ assert overlapHeight == ((ay2<by2?ay2:by2) - (ay1>by1?ay1:by1)); */
        /*@ assert overlapWidth <= (ax2-ax1) && overlapWidth <= (bx2-bx1); */
        /*@ assert overlapHeight <= (ay2-ay1) && overlapHeight <= (by2-by1); */

        int overlapArea = (overlapWidth>0?overlapWidth:0) * (overlapHeight>0?overlapHeight:0);
        /*@ assert overlapArea >= 0; */
        /*@ assert overlapArea == ((overlapWidth>0?overlapWidth:0) * (overlapHeight>0?overlapHeight:0)); */

        return area1 + area2 - overlapArea;
}
