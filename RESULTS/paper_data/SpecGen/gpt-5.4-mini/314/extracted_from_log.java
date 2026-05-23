import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires radius >= 0;
    //@ ensures \result >= 0;
    //@ ensures \result <= (2 * radius) * (2 * radius);
    public static int countRectangles(int radius) {
        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        //@ maintaining 0 <= rectangles && rectangles <= (a - 1) * (2 * radius);
        //@ maintaining 1 <= a && a <= 2 * radius + 1;
        //@ decreases 2 * radius - a + 1;
        for (int a = 1; a <= 2 * radius; a++) {
            //@ maintaining 0 <= rectangles && rectangles < (a - 1) * (2 * radius);  
            //@ maintaining 1 <= b && b <= 2 * radius + 1;
            //@ decreases 2 * radius - b + 1;
            for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
        }
        return rectangles;
    }
}