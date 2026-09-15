/*@
    requires radius > 0;
    ensures \result >= 0;
*/
int countRectangles(int radius);

int countRectangles(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;

        /*@
            loop invariant 1 <= a <= 2 * radius + 1;
            loop assigns a, rectangles;
            loop variant 2 * radius - a + 1;
        */
        for (int a = 1; a <= 2 * radius; a++) {
            /*@
                loop invariant 1 <= b <= 2 * radius + 1;
                loop invariant rectangles >= 0;
                loop assigns b, rectangles;
                loop variant 2 * radius - b + 1;
            */
            for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
        }
        return rectangles;
}
