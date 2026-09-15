/*@
    requires radius >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == \sum integer A; 1 <= A <= 2*radius;
                              (\sum integer B; 1 <= B <= 2*radius;
                                   ((A*A + B*B <= (2*radius)*(2*radius)) ? 1 : 0));
*/
int countRectangles(int radius) {

        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        /*@
            loop invariant 1 <= a <= 2*radius + 1;
            loop invariant rectangles == \sum integer A; 1 <= A <= a-1;
                                         (\sum integer B; 1 <= B <= 2*radius;
                                              ((A*A + B*B <= diameterSquare) ? 1 : 0));
            loop assigns rectangles;
            loop variant 2*radius - a + 1;
        */
        for (int a = 1; a <= 2 * radius; a++) {
            /*@
                loop invariant 1 <= b <= 2*radius + 1;
                loop invariant rectangles ==
                    \sum integer A; 1 <= A <= a-1;
                        (\sum integer B; 1 <= B <= 2*radius;
                             ((A*A + B*B <= diameterSquare) ? 1 : 0))
                    + (\sum integer B; 1 <= B <= b-1;
                             ((a*a + B*B <= diameterSquare) ? 1 : 0));
                loop assigns rectangles;
                loop variant 2*radius - b + 1;
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
