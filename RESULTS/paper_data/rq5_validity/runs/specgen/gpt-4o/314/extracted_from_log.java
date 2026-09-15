import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires radius >= 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int a; 1 <= a && a <= 2 * radius; (\sum int b; 1 <= b && b <= 2 * radius; (a * a + b * b <= (2 * radius) * (2 * radius) ? 1 : 0)));
    public static int countRectangles(int radius) {
        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        
        //@ maintaining 1 <= a && a <= 2 * radius + 1;
        //@ maintaining rectangles == (\sum int x; 1 - 1 <= x && x <= a; (\sum int y; 1 < y && y <= 2 * radius; (x * x + y * y < diameterSquare ? 1 : 0)));  
        //@ decreases 2 * radius - a + 1;
        for (int a = 1; a <= 2 * radius; a++) {
            //@ maintaining 1 <= b && b <= 2 * radius + 1;
            //@ maintaining rectangles == (\sum int x; 1 <= x && x < a; (\sum int y; 1 <= y && y <= 2 * radius; (x * x + y * y <= diameterSquare ? 1 : 0))) + (\sum int y; 1 <= y && y < b; (a * a + y * y <= diameterSquare ? 1 : 0));
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