class ComputeOverlapBranch {
    /*@ ensures \result >= 0; @*/
 
    /*@ ensures \result > 0 ==> (\exists int x1, x2, y1, y2; 
          x1 == Math.max(ax1, bx1) && x2 == Math.min(ax2, bx2) && 
          y1 == Math.max(ay1, by1) && y2 == Math.min(ay2, by2) && 
          x2 > x1 && y2 > y1 && \result == (x2 - x1) * (y2 - y1)); @*/
    public int computeOverlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
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
}
