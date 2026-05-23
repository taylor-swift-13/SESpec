/**
 * This class computes the overlapping area of two rectangles.
 */
public class ComputeAreaBranch {

    /**
     * Computes the overlapping area of two rectangles defined by their coordinates.
     *
     * @param ax1 The x-coordinate of the bottom-left corner of the first rectangle.
     * @param ay1 The y-coordinate of the bottom-left corner of the first rectangle.
     * @param ax2 The x-coordinate of the top-right corner of the first rectangle.
     * @param ay2 The y-coordinate of the top-right corner of the first rectangle.
     * @param bx1 The x-coordinate of the bottom-left corner of the second rectangle.
     * @param by1 The y-coordinate of the bottom-left corner of the second rectangle.
     * @param bx2 The x-coordinate of the top-right corner of the second rectangle.
     * @param by2 The y-coordinate of the top-right corner of the second rectangle.
     * @return The overlapping area of the two rectangles. If they do not overlap, returns 0.
     * 
     * @ensures \result == (\max(0, (\min(ax2, bx2) - \max(ax1, bx1)))) 
     *                  * (\max(0, (\min(ay2, by2) - \max(ay1, by1))));
     */
    public static int computeOverlapArea(int ax1, int ay1, int ax2, int ay2,
                                         int bx1, int by1, int bx2, int by2) {
        // Calculate the overlap in the x-direction
        int overlapWidth = Math.max(0, Math.min(ax2, bx2) - Math.max(ax1, bx1));
        
        // Calculate the overlap in the y-direction
        int overlapHeight = Math.max(0, Math.min(ay2, by2) - Math.max(ay1, by1));
        
        // Return the overlapping area
        return overlapWidth * overlapHeight;
    }
}