/*@
    requires radius >= 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int countRectangles(int radius);

#include <limits.h>

/*@
    requires radius >= 0;
    requires 2 * radius <= INT_MAX;
    requires 4 * radius * radius <= INT_MAX;
    assigns \nothing;
    ensures \result >= 0;
*/
int countRectangles(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        /*@
            loop invariant 1 <= a <= diameter + 1;
            loop invariant 0 <= rectangles <= (a - 1) * diameter;
            loop assigns a, rectangles, diameterSquare;
            loop variant diameter - a + 1;
        */
        for (int a = 1; a <= 2 * radius; a++) {
            /*@
                loop invariant 1 <= b <= diameter + 1;
                loop invariant 0 <= rectangles <= a * diameter;
                loop assigns b, rectangles;
                loop variant diameter - b + 1;
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
